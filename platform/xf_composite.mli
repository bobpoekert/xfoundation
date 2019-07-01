type gl_context
type gl_matrix
type gl_texture
type gl_shader
type quad 
type color
type image

type text_align

val shader_make: gl_context -> string -> string -> gl_shader

val quad_make: gl_texture -> gl_shader -> quad
val quad_make_vanilla: gl_context -> gl_texture -> quad
val quad_translate: quad -> float -> float -> quad 
val quad_scale: quad -> float -> float -> quad 
val quad_rotate: quad -> float -> quad
val quad_set_shader: quad -> gl_shader -> quad

val render_quads: gl_context -> quad list -> unit 
val render_loop: gl_context -> (gl_context -> float) -> unit

val text_quad: gl_context -> float -> float -> string ->
  text_size:float ->
  font:string -> 
  line_height:float -> 
  color:color -> 
  quad

val image_quad: gl_context -> image -> quad

val load_image_url: string -> (image -> unit)

