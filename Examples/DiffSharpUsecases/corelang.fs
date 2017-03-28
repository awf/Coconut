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

let (.+) (c1: Cardinality) (c2: Cardinality): Cardinality =
  Card((cardToInt c1) + (cardToInt c2))

let (.-) (c1: Cardinality) (c2: Cardinality): Cardinality =
  Card((cardToInt c1) - (cardToInt c2))

let length<'a> (v: array<'a>): Cardinality = 
  Card v.Length

let inline build<'a> (size: Cardinality) (f: Index -> 'a): array<'a> =
  [|for i = 0 to ((cardToInt size) - 1) do yield (f i)|]
   //let inputLength = cardToInt size
   //let result = Microsoft.FSharp.Collections.Array.zeroCreate inputLength
   //System.Threading.Tasks.Parallel.For(0, inputLength, fun i -> 
   //    result.[i] <- f i) |> ignore 
   //result 

let fold<'a, 'b> (f: 'b -> 'a -> 'b) (z: 'b) (range: array<'a>): 'b = 
  Array.fold (fun acc cur -> f acc cur) z range

let numberPrint (v: Number): Unit = 
  printfn "%f" v


let vectorPrint (v: Vector): Unit = 
  printfn "[%s]" (String.concat ", " (Array.map (sprintf "%f") v))

let matrixPrint (v: Matrix): Unit = 
  printf "[\n   "
  Array.iteri (fun i x -> (if(i <> 0) then printf " , " else ()); vectorPrint x) v
  printfn "]"