module types

type Number = double
type Vector = double array
type Matrix = Vector array
type Matrix3D = Matrix array
type Index = int

type Storage = VS of Vector
             | MS of Matrix

type Cardinality = Card of int

(*
type Shape = FlatShape   of Cardinality
           | VectorShape of Shape * Cardinality
*)
type NestedShape<'S> = | NestedShape of 'S * Cardinality
type VectorShape   = Cardinality
type MatrixShape   = NestedShape<VectorShape>
type Matrix3DShape = NestedShape<MatrixShape>

type Timer = System.Diagnostics.Stopwatch

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

type CMirror(Method : string) =
    inherit System.Attribute()
    member this.Method = Method

type DontInline() = 
    inherit System.Attribute()

type DontOptimize() = 
    inherit System.Attribute()

type CMacro() =
    inherit System.Attribute()
    abstract member ShouldLetBind: unit -> bool
    default this.ShouldLetBind () = true

type CMonomorphicMacro() =
    inherit CMacro()
    override this.ShouldLetBind () = false
