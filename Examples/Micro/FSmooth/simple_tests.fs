[<ReflectedDefinition>]
module simple_tests

open corelang
open types
open utils
open cardinality

let rows (m: Matrix): Cardinality = 
  length m