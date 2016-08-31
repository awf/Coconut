module cardinality

open types

let cardToInt (c: Cardinality): int = 
  match c with | Card i -> i

let (.+) (c1: Cardinality) (c2: Cardinality): Cardinality =
  Card((cardToInt c1) + (cardToInt c2))

let (.-) (c1: Cardinality) (c2: Cardinality): Cardinality =
  Card((cardToInt c1) - (cardToInt c2))

let shapeElem<'Shape> (s: NestedShape<'Shape>): 'Shape =
  let (NestedShape(se, _)) = s in se

let shapeCard<'Shape> (s: NestedShape<'Shape>): Cardinality =
  let (NestedShape(_, c)) = s in c

let flatShapeCard (s: Cardinality): Cardinality =
  s

let vectorShape<'Shape> (s: 'Shape) (c: Cardinality): NestedShape<'Shape> =
  NestedShape(s, c)

let flatShape (c: Cardinality): Cardinality =
  c

[<CMacro()>]
let rec width<'Shape> (s: 'Shape): Cardinality = 
  match s.GetType() with
  | t when t = typeof<Cardinality> -> unbox<Cardinality>(s)
  | t when t = typeof<VectorShape> -> 
    let tup = unbox<VectorShape>(s)
    Card ((cardToInt (shapeElem tup)) * (cardToInt (shapeCard tup)))
  | t when t = typeof<MatrixShape> -> 
    let tup = unbox<MatrixShape>(s)
    Card ((cardToInt (width (shapeElem tup))) * (cardToInt (shapeCard tup)))
  | _                              -> failwithf "Cannot compute width for `%A`" s