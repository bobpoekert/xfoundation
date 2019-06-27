open Bigarray

type texture
type fragment_shader
type handle

type sprite = {
  id:handle;
  tex:texture;
  shader:fragment_shader;
}

type point_array = (float, float32_elt, c_layout) Array1.t
type transformation_matrix = (float, float32_elt, c_layout) Array2.t

type fragment_shader
type vertex_shader
type shader = Fragment_shader of fragment_shader | Vertex_shader of vertex_shader
type texture
type layout_impl
type shader_program

type layout = {
  quads_tree: sprite Quadtree.t;
  impl: layout_impl;
}

val make : string -> float -> float -> layout
val transform : layout -> transformation_matrix -> unit

val compile_fragment_shader : layout -> string -> fragment_shader
val compile_vertex_shader : layout -> string -> vertex_shader
val cached_vertex_shader : string -> (layout -> vertex_shader)
val link_shaders : layout -> shader list -> shader_program

val attach_texture : sprite -> texture -> unit 
val make_sprite : layout -> float -> float -> sprite
val attach_sprite : layout -> sprite -> unit
val paint : layout -> unit
val every_frame : (double -> unit) -> unit