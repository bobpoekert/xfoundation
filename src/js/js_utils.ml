open Bigarray


let bigarray_of_typed_array inp = 
  let make = Js.Unsafe.js_expr "caml_ba_create_from" in 
  let kind = match inp#_cotnent_type_ with 
    | "Int8Array" -> 2 
    | "Uint8Array" -> 3
    | "Uint8ClampedArray" -> 3
    | "Int16Array" -> 4 
    | "Uint16Array" -> 5
    | "Int32Array" -> 6 
    | "Float32Array" -> 0 
    | "Float64Array" -> 1 
    | _ -> raise (Invalid_argument (Printf.sprintf "cannot convert array type %s" inp##.name)) in 
    let length = inp#length in 
  Js.Unsafe.fun_call make [| 
    Js.Unsafe.inject inp;
    Js.Unsafe.inject Js.null;
    Js.Unsafe.inject 0;
    Js.Unsafe.inject kind;
    Js.Unsafe.inject layout;
    Js.Unsafe.inject [| length; |]
  |]

let typed_array_of_bigarray inp = 
  (Js.Unsafe.inject inp)##.data
