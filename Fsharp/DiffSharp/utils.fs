module utils

let arrayPrint (v: double[]): Unit = 
  printfn "(%s)" (String.concat ", " (Array.map (sprintf "%f") v))

let numberPrint (v: double): Unit = 
  printfn "%f" v

let arrayRange (s: int) (e: int): double[] = 
  [|for i = s to e do yield (double i)|]

let arrayMapToMatrix (f: double -> double[]) (arr: double[]): double[][] = 
  Array.map f arr