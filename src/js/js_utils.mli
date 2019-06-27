open Bigarray
open Typed_array

val bigarray_of_typed_array : ('a, 'b) typedArray -> ('c, 'd, c_layout) Array1.t
val typed_array_of_bigarray : ('c, 'd, c_layout) Array1.t -> ('a, b) typedArray