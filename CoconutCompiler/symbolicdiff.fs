module symbolicdiff

open corelang
open rules_d
open FSharp.Quotations
open phase_based_optimizer

let symdiff (exp: Expr): Expr = 
  exp
    |> trans [ruleengine.compilePatternToRule <@ add_d @>;
                 ruleengine.compilePatternToRule <@ mult_d @>; var_d; chain_rule] 


let test_symdiff () = 
    printfn "symdiff: %A" (symdiff <@ fun (x: double) -> diff (1. * 2.) x @>)
    printfn "symdiff2: %A" (symdiff <@ fun (x: double) -> diff (let v = 1. * 2. in v) x @>)
    printfn "symdiff3: %A" (symdiff <@ fun (x: double) (y: double) (z: double) -> diff (let v = y * z in v) x @>)
    ()