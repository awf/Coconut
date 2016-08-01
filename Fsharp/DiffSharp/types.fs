module types

type Number = double
type Vector = double array
type Matrix = Vector array
type Matrix3D = Matrix array
type Index = int

type Storage = VS of Vector
             | MS of Matrix

type AnyNumeric = 
  | ZeroD of Number
  | OneD of Vector
  | TwoD of Matrix
  | ThreeD of Matrix3D
  | Idx of Index
  | Fun of (AnyNumeric -> AnyNumeric)
and
  Environment = Map<string, AnyNumeric>
and
  Closure<'a, 'b> = {
    lambda: Environment -> ('a -> 'b);
    env: Environment
  }

type Timer = System.Diagnostics.Stopwatch

type CMirror(Method : string) =
    inherit System.Attribute()
    member this.Method = Method

type DontInline() = 
    inherit System.Attribute()

type DontOptimize() = 
    inherit System.Attribute()