module types

type Number = double
type Vector = double array
type Matrix = Vector array
type Index = int

type AnyNumeric = 
  | ZeroD of Number
  | OneD of Vector
  | TwoD of Matrix
  | Idx of Index

type Timer = System.Diagnostics.Stopwatch

type CMirror(Method : string) =
    inherit System.Attribute()
    member this.Method = Method

type DontInline() = 
    inherit System.Attribute()