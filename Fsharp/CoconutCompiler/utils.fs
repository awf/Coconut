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
let toc(t: Timer) (s:string) = 
  t.Stop()
  printfn "Time[%s]: %d ms" s t.ElapsedMilliseconds

let currentTimeString(): string =
  sprintf "%s_%s" (System.DateTime.Now.ToShortDateString().Replace("/", "-")) (System.DateTime.Now.ToLongTimeString().Replace(":", "-"))

(** Utility Methods (Which are only used in the meta language) **)

let listDiff list1 list2 = 
  List.filter (fun x -> not (List.exists (fun y -> x = y) list2)) list1

let mutable variable_counter = 0

(* Generates a unique variable name *)
let newVar (name: string): string = 
  variable_counter <- variable_counter + 1
  let id = variable_counter
  sprintf "%s%d" name id