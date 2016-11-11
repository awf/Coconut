module corelang

type Number = double
type Vector = double array
type Matrix = Vector array
type Matrix3D = Matrix array
type Index = int

type Storage = VS of Vector
             | MS of Matrix

type Cardinality = Card of int


let cardToInt (c: Cardinality): int = 
  match c with | Card i -> i

let length<'a> (v: array<'a>): Cardinality = 
  Card v.Length

let inline build<'a> (size: Cardinality) (f: Index -> 'a): array<'a> =
  [|for i = 0 to ((cardToInt size) - 1) do yield (f i)|]
   //let inputLength = cardToInt size
   //let result = Microsoft.FSharp.Collections.Array.zeroCreate inputLength
   //System.Threading.Tasks.Parallel.For(0, inputLength, fun i -> 
   //    result.[i] <- f i) |> ignore 
   //result 
