type gl_context
type gl_matrix
type gl_texture
type gl_shader
type quad 
type aabb (* quads are dimensionless but aabb's have dimension *)
type color = (float * float * float * float)

type text_align

val shader_make: gl_context -> string -> string -> gl_shader
val gl_context_make: unit -> gl_context

val quad_make: gl_texture -> gl_shader -> quad
val quad_reset_matrix: quad -> quad 
val quad_make_vanilla: gl_context -> gl_texture -> quad
val quad_translate: quad -> float -> float -> quad 
val quad_scale: quad -> float -> float -> quad 
val quad_rotate: quad -> float -> quad
val quad_set_shader: quad -> gl_shader -> quad
val quad_destroy: quad -> unit

val aabb_mat: aabb -> gl_matrix 
val aabb_reset_matrix: aabb -> aabb 

val render_quads: gl_context -> quad list -> unit 
val render_loop: gl_context -> (gl_context -> float) -> unit

val text_quad: gl_context -> 
  ?text_size:float ->
  ?font:string -> 
  ?line_height:float -> 
  ?color:color -> float -> float -> string ->
  quad


val load_image_url: gl_context -> string -> aabb Lwt.t

