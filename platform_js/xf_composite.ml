open Js_of_ocaml

let shader_make gl vertex_source fragment_source = 
  Js.Unsafe.global##makeShader gl vertex_source fragment_source

let gl_context_make () = 
  Js.Unsafe.global##createGLContext

let ortho_matrix_gen = Js.Unsafe.global##.orthographicMat

type gl_context
type gl_matrix
type gl_texture
type gl_shader
type color = (float * float * float * float)
type native_image

type image = {
  native: native_image;
  width: float;
  height: float;
}

type quad = {
  matrix: gl_matrix;
  texture: gl_texture;
  shader: gl_shader;
}

type aabb = {
  quad: quad;
  x: float;
  y: float;
  width: float;
  height: float;
}

type text_align = [`Left | `Right | `Center | `Start | `End]

let quad_make tex shader : quad= 
  {
    matrix = ortho_matrix_gen;
    texture = tex;
    shader = shader;
  }

let aabb_make quad x y w h : aabb = 
  {
    quad = quad;
    x = x;
    y = y;
    width = w;
    height = h;
  }

let xywh_mat x y w h = 
  ortho_matrix_gen 
  |> Js.Unsafe.global##translateMat x y
  |> Js.Unsafe.global##scaleMat w h 

let aabb_mat a = xywh_mat a.x a.y a.width a.height

let aabb_reset_matrix (a:aabb) : aabb = 
  {a with quad = {a.quad with matrix = aabb_mat a }}

let aabb_update a x y w h = 
  {
    quad = {a.quad with matrix = xywh_mat x y w h}
    x = x;
    y = y;
    width = w;
    height = h;
  }

let quad_reset_matrix quad = 
  {quad with matrix=ortho_matrix_gen}

let quad_make_vanilla gl tex = 
  quad_make tex (Js.Unsafe.global##vanillaTextureShader gl)

let quad_translate inp x y = 
  let old = inp.matrix in 
  {inp with matrix = Js.Unsafe.global##translateMat old x y}

let quad_scale inp w h = 
  let old = inp.matrix in 
  {inp with matrix = Js.Unsafe.global##scaleMat old w h}

let quad_rotate inp angle_in_radians = 
  let old = inp.matrix in 
  {inp with matrix = Js.Unsafe.global##rotateMat old angle_in_radians}

let quad_set_shader inp shader = 
  {inp with shader=shader}

let quad_destroy gl quad = 
  gl##destroyTexture quad.texture

let unpack_quad quad = 
  object%js
    val matrix = quad.matrix
    val texture = quad.texture 
    val shader = quad.shader
  end


let render_quads gl quads = 
  let unpacked_quads = List.map unpack_quad quads |> Array.of_list in 
  Js.Unsafe.global##renderQuads gl (Js.array unpacked_quads)

let render_loop gl cb = 
  Js.Unsafe.global##renderLoop gl (Js.wrap_callback cb)

let text_quad (gl:gl_context) 
  ?(text_size=20.) ?(font="sans-serif")
  ?(line_height=25.) ?(color=(0.0, 0.0, 0.0, 1.0))
  (w:float) (h:float) (text:string) = 

  let tex = Js.Unsafe.global##textTexture gl w h text text_size font line_height color in 
  quad_scale (quad_make_vanilla gl tex) w h

let image_aabb gl img = 
  let tex = Js.Unsafe.global##imageTexture gl img.native in 
  {
    width = img.width;
    height = img.height;
    quad = quad_scale (quad_make_vanilla gl tex) img.width img.height;
    x = 0;
    y = 0;
  }

let load_image_url gl url = 
  let promise, resolver = Lwt.task () in 
  let _ = Js.Unsafe.global##loadImageUrl url (Js.wrap_callback (fun img w h -> 
    Lwt.wakeup_later resolver {
      native = img;
      width = Js.float_of_number w;
      height = Js.float_of_number h;
    }
  )) in promise