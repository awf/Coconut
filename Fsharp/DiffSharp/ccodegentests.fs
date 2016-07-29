﻿[<ReflectedDefinition>]
module ccodegentests

open types
open corelang

let closure_bug1 (m1: Matrix) (m2: Matrix): Matrix = 
  matrixBuild (10) (fun i -> vectorBuild 20 (fun j -> double(j)))

let closure_bug2 (m1: Matrix) (m2: Matrix): Matrix = 
  matrixBuild (10) (fun i -> vectorBuild 20 (fun j -> double(i + j)))