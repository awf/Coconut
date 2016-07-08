module utils

let arrayPrint (v: double[]): Unit = 
  printf "(%s)" (String.concat ", " (Array.map (sprintf "%f") v))