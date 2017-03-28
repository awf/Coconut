module cardinality

open types

let cardToInt (c: Cardinality): int = 
  match c with | Card i -> i

let (.+) (c1: Cardinality) (c2: Cardinality): Cardinality =
  Card((cardToInt c1) + (cardToInt c2))

let (.-) (c1: Cardinality) (c2: Cardinality): Cardinality =
  Card((cardToInt c1) - (cardToInt c2))

[<CMonomorphicMacro()>]
let shapeElem<'Shape> (s: NestedShape<'Shape>): 'Shape =
  let (NestedShape(se, _)) = s in se

[<CMonomorphicMacro()>]
let shapeCard<'Shape> (s: NestedShape<'Shape>): Cardinality =
  let (NestedShape(_, c)) = s in c

[<CMonomorphicMacro()>]
let nestedShape<'Shape> (s: 'Shape) (c: Cardinality): NestedShape<'Shape> =
  NestedShape(s, c)

let HEADER_SIZE = Card 2

[<CMonomorphicMacro()>]
let rec width<'Shape> (s: 'Shape): Cardinality = 
  match s.GetType() with
  | t when t = typeof<Cardinality> -> unbox<Cardinality>(s) .+ HEADER_SIZE
  | t when t = typeof<MatrixShape> -> 
    let tup = unbox<MatrixShape>(s)
    Card ((cardToInt (width (shapeElem tup))) * (cardToInt (shapeCard tup)))
  | _                              -> failwithf "Cannot compute width for `%A`" s