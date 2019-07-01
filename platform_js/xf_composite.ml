open Js_of_ocaml

type m4_mat

let shader_make gl vertex_source fragment_source = 
  Js.Unsafe.global##makeShader gl vertex_source fragment_source

let ortho_matrix_gen = Js.Unsafe.global##.orthographicMat

type gl_context
type gl_matrix
type gl_texture
type gl_shader
type image
type color = (float * float * float * float)

type quad = {
  matrix: gl_matrix;
  texture: gl_texture;
  shader: gl_shader;
}

type text_align = [`Left | `Right | `Center | `Start | `End]

let quad_make tex shader : quad= 
  {
    matrix = ortho_matrix_gen;
    texture = tex;
    shader = shader;
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

let text_quad gl w h text
  ?(text_size=20.) ?(font="sans-serif")
  ?(line_height=25.) ?(color=(0.0, 0.0, 0.0, 1.0)) () =

  let tex = Js.Unsafe.global##textTexture gl w h text text_size font line_height color in 
  quad_scale (quad_make_vanilla gl tex) w h

let image_quad gl img = 
  Js.Unsafe.global##imageQuad gl img 

let load_image_url url cb = 
  Js.Unsafe.global##loadImageUrl url (Js.wrap_callback cb)