type 'a quadtree_item = {
  value: 'a ;
  x_min: float;
  y_min: float;
  x_max: float;
  y_max: float;
}

type 'a quadtree_node = {
  x_min: float;
  y_min: float;
  x_max: float;
  y_max: float;
  north_west: 'a quadtree_node option;
  north_east: 'a quadtree_node option;
  south_west: 'a quadtree_node option;
  south_east: 'a quadtree_node option;
  payload: 'a quadtree_item list
}

type 'a t = 'a quadtree_node option

val make : unit -> 'a t
val point_test : 'a t -> float -> float -> 'a list
val add_element : 'a t -> 'a -> float -> float -> float -> float -> 'a t
val remove_element : 'a t -> 'a -> 'a t