module linalg

open corelang

let inline iterateNumber (f: Number -> Index -> Number) (z: Number) (s: Cardinality) (e: Cardinality): Number = 
  let mutable res = z
  for i=(cardToInt s) to (cardToInt e) do
    res <- f res i
  res
