
let make item = None

let contains_item tree item = 
  match tree with 
  | None -> false
  | Some(tree) -> 
    (tree.x_max >= item.x_max) && 
    (tree.x_min <= item.x_min) &&
    (tree.y_max >= item.y_max) &&
    (tree.y_min <= item.y_min)

let contains_point tree x y = 
  match tree with 
  | None -> false 
  | Some(tree) ->
    (x >= tree.x_min) && 
    (x <= tree.x_max) && 
    (y >= tree.y_min) && 
    (y <= tree.y_max)

let node_wraps item = 
  {
    x_min = item.x_min;
    x_max = item.x_max;
    y_min = item.y_min;
    y_max = item.y_max;
    north_west = None;
    north_east = None;
    south_west = None;
    south_east = None;
    payload = [item]
  }

let add_payload_item tree item = 
  {tree with 
    payload = (item :: payload);
    x_min = min tree.x_min item.x_min;
    x_max = max tree.x_max item.x_max;
    y_min = min tree.y_min item.y_min;
    y_max = max tree.y_max item.y_max;
  }

let rec update_element tree item updater = 
  match tree with 
  | None -> updater tree
  | Some(tree) -> (
    if (contains_item tree.north_west item) then
      {tree with north_west = update_element tree.north_west item updater}
    else if (contains_item tree.north_east) then 
      {tree with north_east = update_element tree.north_east item updater}
    else if (contains_item tree.south_west) then 
      {tree with south_west = update_element tree.south_west item updater}
    else if (contains_item tree.south_east) then 
      {tree with south_east = update_element tree.south_east item updater}
    else
      updater tree
  )

let add_element tree item =
  update_element tree item (fun tree -> 
    match tree with 
    | None -> node_wraps item 
    | Some(tree) -> {tree with payload = (item :: payload)}
  )

let remove_element tree item =
  update_element tree item (fun tree -> 
    match tree with 
    | None -> None 
    | Some(tree) -> {tree with payload = List.filter (fun v -> v != item) payload}
  )

let rec inner_point_test x y tree res = 
  match tree with 
  | None -> res 
  | Some(tree) -> (
    let res = if (contains_point tree x y) then 
      List.append (List.filter (fun v -> contains_point v x y) tree.payload) res
      else res in 
    if (contains_point tree.north_west x y) then 
      inner_point_test x y tree.north_west res 
    else if (contains_point tree.north_east x y) then 
      inner_point_test x y tree.north_east res 
    else if (contains_point tree.south_west x y) then 
      inner_point_test x y tree.south_west res 
    else if (contains_point tree.south_east x y) then 
      inner_point_test x y tree.south_east res 
    else res
  )

let point_test tree x y = inner_point_test x y tree []

let rec walk tree fn = 
  match tree with 
  | None -> ()
  | Some(tree) -> (
    List.iter (fun item -> fn item.value) tree.payload;
    walk tree.north_west fn;
    walk tree.north_east fn;
    walk tree.south_west fn;
    walk tree.south_east fn;
  )
