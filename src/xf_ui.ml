open Xf_composite

(*

Theory of operation
---

The screen is composed of a tree of ui elements. 

These trees are lazy, meaning elements start out "unrealized" as functions that return elements.

These functions must be pure and their arguments must be hashable. 

Every screen update, the application returns a new (unrealized) element tree. 

We keep an index of elements from the previous screen update that let us look up elements by their hashes. 

Because element functions are pure, we know that a subtree rooted at a node with a given hash will always be the same. 

This allows us to carry forward whole subtrees from the previous frame if they don't need to be updated. 

Realized elements contain an aabb (which has a texture and a shader) and a list of child elements. 

The child elements also start unrealized. 

This lets us write applications as pure functions of the data in our app's datastore but get the performance we'd get if we put state in the UI.

*)


type screen = {
  prev_frame_boxes: Elem_cache.t;
  gl_ctx: Xf_composite.gl_context;
  shader_cache: ((stirng * string), gl_shader) Hashtbl.t
}

let make_shader scn vertex_source fragment_source = 
  let key = (vertex_source, fragment_source) in 
  try Hashtbl.find scn.shader_cache key with Not_found -> (
    let res = shader_make scn.gl_ctx vertex_source fragment_source in 
    let _ = Hashtbl.replace scn.shader_cache key res in 
    res
  )

type realized_ui_element = {
  content: aabb;
  children: ui_element list;
}

type unrealized_ui_element = {
  content: screen -> realized_ui_element;
}

type ui_element = {
  argument_hash: int;
  content: Realized of realized_ui_element | Unrealized of unrealized_ui_element;
}

module Elem_cache = Set.Make(struct 
  type t = ui_element
  let compare a b = compare a.argument_hash b.argument_hash
)

let elem_cache_of_list l = 
  List.fold_left (fun cache k -> Elem_cache.add k cache) Elem_cache.empty l

let rec elem_cache_of_tree (tree:realized_ui_element) = 
  List.fold_left
    (fun cache k -> Elem_cache.union cache (elem_cache_of_tree k)) 
    (Elem_cache.singleton tree)
    tree.children

let elem_cache_of_trees trees = 
  List.fold_left Elem_cache.union Elem_cache.empty trees

let ui_element_make arg_hash generator = 
  {
    argument_hash = arg_hash;
    content = Unrealized(generator)
  }

let realize_element scn elem = 
  match elem with 
  | Realized(v) -> v 
  | Unrealized(f) -> f scn

let rec reify_screen scn element = 
  let cache = scn.prev_frame_boxes in
  match Elem_cache.find_first_opt cache element with 
  | Some(v) -> (match v with 
    | Realized(v) -> v 
    | Unrealized(v) -> raise Not_found)
  | None -> let res = (realize_element scn element) in 
    {res with children = List.map (reify_screen scn) res.children}

let boxes_of_elems elems = List.map (fun v -> v.content) elems
let quads_of_elems elems = List.map (fun v -> v.content.quad) elems

let render_screen scn element_trees = 
  let reified = List.map (reify_screen scn) element_trees in 
  let quads = List.concat (List.map quads_of_elems reified) in 
  let _ = render_quads scn.gl_ctx quads in
  let old_cache = scn.prev_frame_boxes in 
  let new_cache = elem_cache_of_trees reified in
  let to_delete = Elem_cache.diff old_cache new_cache in 
  let _ = Elem_cache.iter (fun v -> quad_destroy v.content.quad) to_delete in 
  {scn with prev_frame_boxes = new_cache}

let run_application app = 
  let gl = gl_context_make () in 
  let screen = ref {gl_ctx=gl; prev_frame_boxes=Elem_cache.empty; } in 
  render_loop gl (fun frame_interval -> 
    screen := render_screen !screen (app ())
  )

let text_element ?(text_size=20.) ?(font="sans-serif")
  ?(line_height=25.) ?(color=(0.0, 0.0, 0.0, 1.0))
  (w:float) (h:float) (text:string) = 
  let hash = (Hashtbl.hash text_size) lxor
             (Hashtbl.hash font) lxor 
             (Hashtbl.hash line_height) lxor 
             (Hashtbl.hash color) lxor 
             (Hashtbl.hash w) lxor
             (Hashtbl.hash h) lxor 
             (Hashtbl.hash text) in 
  let gen = (fun scn -> {
    tex = aabb_make (text_quad scn.gl_ctx text_size font line_height color w h text) 0.0 0.0 w h;
    children = [];
  }) in ui_element_make hash gen

let image_element img img_id = 
  (* img_id is a value that's unique to this image, eg: its url *)
  let hash = Hashtbl.hash img_id in 
  let gen = (fun scn -> {
    tex = image_aabb scn.gl_ctx img;
    children = [];
  }) in ui_element_make hash gen

let custom_shader_element vertex_source fragment_source texture x y width height id = 
  let hash = Hashtbl.hash id in 
  let gen = (fun scn -> {
    tex = aabb_make
      (quad_make texture (make_shader scn vertex_source fragment_source))
      x y width height;
    children = [];
  }) in ui_element_make hash gen