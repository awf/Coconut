module utils

open types
open System
open System.Diagnostics
open System.IO

(** Timing **)

[<CMirror("tic")>]
let tic(): Timer = 
  Stopwatch.StartNew()

[<CMirror("toc")>]
let toc(t: Timer) = 
  t.Stop()
  printfn "Time: %d ms" t.ElapsedMilliseconds

(** Utility Methods (Which are only used in the meta language) **)

let listDiff list1 list2 = 
  List.filter (fun x -> not (List.exists (fun y -> x = y) list2)) list1
