module types

type Number = double
type Vector = double array
type Matrix = Vector array
type Index = int

type AnyNumeric = 
  | ZeroD of Number
  | OneD of Vector
  | TwoD of Matrix