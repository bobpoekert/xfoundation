
type context = {
  canvas: 'a Js.t,
  context: 'b Js.t
}

let create_context window_name _width _height : context = 
  (* width and height is only for the initial size, and that's only relevant on native desktop *)
  let doc = Dom_html.document in 
  let _ = doc##.title := window_name in 
  let canvas = doc##createElement "canvas" in 
  let _ = canvas##setAttribute "width" "100%" in 
  let _ = canvas##setAttribute "height" "100%" in 
  let _ = (doc##body)##appendChild canvas in 
  let ctx = canvas##getContext "webgl" in 
  Lwt.return {
    canvas: canvas,
    context: ctx
  }

let render ctx callback = 
  (* on some platforms we need to do GL calls on a specific thread *)
  (* this function is here to schedule GL-using code onto that thread *)
  (* we don't need to do that on web so this is a stub *)
  Lwt.return (callback ctx)

let scissor ctx x y width height = 
  (ctx.context)##scissor x y width height

let viewport ctx x y width height = 
  (ctx.context)##viewport x y width height

let active_texture ctx tex = 
  (ctx.context)##activeTexture tex 

let blend_color ctx r g b a =
  (ctx.context)##activeTexture context r g b a 

let translate_blend_mode ctx blend_mode = 
  match blend_mode 
  | `FUNC_ADD -> ctx##LINE_WIDTH 
  | `FUNC_SUBTRACT -> ctx##FUNC_SUBTRACT 
  | `FUNC_REVERSE_SUBTRACT -> ctx##FUNC_REVERSE_SUBTRACT 
  | `FUNC_MIN -> ctx##FUNC_MIN 
  | `FUNC_MAX -> ctx##FUNC_MAX

let blend_equation ctx blend_mode = 
  (ctx.context)##bendEquation (translate_blend_mode_rgb ctx blend_mode)

let bend_equation_separate ctx mode_rgb mode_alpha = 
  (ctx.context)##blendEquationSeparate
    (translate_blend_mode ctx mode_rgb)
    (translate_blend_mode ctx mode_alpha)

let clear_color ctx r g b a =
  (ctx.context)##clearColor r g b a 

let clear_depth ctx depth =
  (ctx.context)##clearDepth depth 

let clear_stencil ctx depth = 
  (ctx.context)##clearStencil depth 

let color_mask ctx r g b a = 
  (ctx.context)##colorMask r g b a

let translate_cull_mode ctx mode = 
  match mode 
  | `FRONT -> (ctx.context)##FRONT
  | `BACK -> (ctx.context)##BACK
  | `FRONT_AND_BACK -> (ctx.context)##FRONT_AND_BACK

let cull_face ctx mode = 
  (ctx.context)##cullFace (translate_cull_mode ctx mode)

let translate_depth_func ctx df = 
  match df
  | `NEVER -> (ctx.context)##NEVER
  | `LESS -> (ctx.context)##LESS
  | `EQUAL -> (ctx.context)##EQUAL
  | `LEQUAL -> (ctx.context)##LEQUAL
  | `GREATER -> (ctx.context)##GREATER
  | `NOTEQUAL -> (ctx.context)##NOTEQUAL
  | `GEQUAL -> (ctx.context)##GEQUAL
  | `ALWAYS -> (ctx.context)##ALWAYS

let set_depth_func ctx df = 
  (ctx.context)##depthFunc (trnaslate_depth_func df)

let depth_mask ctx mask = 
  (ctx.context)##depthMask mask 

let depth_range ctx z_near z_far = 
  (ctx.context)##depthRange z_near z_far 

let disable_blend ctx = 
  let context = ctx.context in 
  context##disable (context##BLEND)

let disable_cull_face ctx = 
  let context = ctx.context in 
  context##disable (context##CULL_FACE)

let disable_depth ctx = 
  let context = ctx.context in 
  context##disable (context##CULL_DEPTH)

let disable_cull_face ctx = 
  let context = ctx.context in 
  context##disable (context##CULL_FACE)

let disable_dither ctx = 
  let context = ctx.context in 
  context##disable (context##DITHER)

let disable_polygon_offset_fill ctx = 
  let context = ctx.context in 
  context##disable (context##POLYGON_OFFSET_FILL)

let disable_sample_alpha_to_coverage ctx = 
  let context = ctx.context in 
  context##disable (context##SAMPLE_ALPHA_TO_COVERAGE)

let disable_sample_coverage ctx = 
  let context = ctx.context in 
  context##disable (context##SAMPLE_COVERAGE)

let disable_scissor_test ctx = 
  let context = ctx.context in 
  context##disable (context##SCISSOR_TEST)

let disable_stencil_test ctx = 
  let context = ctx.context in 
  context##disable (context##STENCIL_TEST)

let disable_rasterizer_discard ctx = 
  let context = ctx.context in 
  context##disable (context##RASTERIZER_DISCARD)

let enable_blend ctx = 
  let context = ctx.context in 
  context##enable (context##BLEND)

let enable_cull_face ctx = 
  let context = ctx.context in 
  context##enable (context##CULL_FACE)

let enable_depth ctx = 
  let context = ctx.context in 
  context##enable (context##CULL_DEPTH)

let enable_cull_face ctx = 
  let context = ctx.context in 
  context##enable (context##CULL_FACE)

let enable_dither ctx = 
  let context = ctx.context in 
  context##enable (context##DITHER)

let enable_polygon_offset_fill ctx = 
  let context = ctx.context in 
  context##enable (context##POLYGON_OFFSET_FILL)

let enable_sample_alpha_to_coverage ctx = 
  let context = ctx.context in 
  context##enable (context##SAMPLE_ALPHA_TO_COVERAGE)

let enable_sample_coverage ctx = 
  let context = ctx.context in 
  context##enable (context##SAMPLE_COVERAGE)

let enable_scissor_test ctx = 
  let context = ctx.context in 
  context##enable (context##SCISSOR_TEST)

let enable_stencil_test ctx = 
  let context = ctx.context in 
  context##enable (context##STENCIL_TEST)

let enable_rasterizer_discard ctx = 
  let context = ctx.context in 
  context##enable (context##RASTERIZER_DISCARD)

let is_enabled_blend ctx = 
  let context = ctx.context in 
  context##is_enabled (context##BLEND)

let is_enabled_cull_face ctx = 
  let context = ctx.context in 
  context##is_enabled (context##CULL_FACE)

let is_enabled_depth ctx = 
  let context = ctx.context in 
  context##is_enabled (context##CULL_DEPTH)

let is_enabled_cull_face ctx = 
  let context = ctx.context in 
  context##is_enabled (context##CULL_FACE)

let is_enabled_dither ctx = 
  let context = ctx.context in 
  context##is_enabled (context##DITHER)

let is_enabled_polygon_offset_fill ctx = 
  let context = ctx.context in 
  context##is_enabled (context##POLYGON_OFFSET_FILL)

let is_enabled_sample_alpha_to_coverage ctx = 
  let context = ctx.context in 
  context##is_enabled (context##SAMPLE_ALPHA_TO_COVERAGE)

let is_enabled_sample_coverage ctx = 
  let context = ctx.context in 
  context##is_enabled (context##SAMPLE_COVERAGE)

let is_enabled_scissor_test ctx = 
  let context = ctx.context in 
  context##is_enabled (context##SCISSOR_TEST)

let is_enabled_stencil_test ctx = 
  let context = ctx.context in 
  context##is_enabled (context##STENCIL_TEST)

let is_enabled_rasterizer_discard ctx = 
  let context = ctx.context in 
  context##is_enabled (context##RASTERIZER_DISCARD)