module cardinality

open types

let cardToInt (c: Cardinality): int = 
  match c with | Card i -> i

let addCard (c1: Cardinality) (c2: Cardinality): Cardinality =
  Card((cardToInt c1) + (cardToInt c2))

let subCard (c1: Cardinality) (c2: Cardinality): Cardinality =
  Card((cardToInt c1) - (cardToInt c2))

let shapeElem (s: Shape): Shape =
  match s with 
  | VectorShape(x, y) -> x 
  | _ -> failwithf "No elem available for the shape `%A`" s

let shapeCard (s: Shape): Cardinality =
  match s with 
  | VectorShape(x, y) -> y 
  | _ -> failwithf "No card available for the shape `%A`" s

let flatShapeCard (s: Shape): Cardinality =
  match s with 
  | FlatShape(x) -> x
  | _ -> failwithf "The following shape is not flat `%A`" s

let vectorShape (s: Shape) (c: Cardinality): Shape =
  VectorShape(s, c)

let flatShape (c: Cardinality): Shape =
  FlatShape(c)