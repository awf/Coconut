#r @"..\packages\NUnit.3.7.1\lib\net45\nunit.framework.dll"
#r @"..\packages\Unquote.3.2.0\lib\net45\Unquote.dll"

#load "Tuple.fs"
#load "VecMat.fs"

open VecMat

let v = Vec (1.,2.,3.)
let m = Mat [| 1.,2.; 3., 4.; 5.,6. |]

GDot.dot(0., m.v, v)