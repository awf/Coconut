module symbolicdiff

open corelang
open rules_d
open FSharp.Quotations
open phase_based_optimizer
open types

let symdiff (exp: Expr): Expr = 
  exp
    |> trans [ruleengine.compilePatternToRule <@ add_d @>;
              ruleengine.compilePatternToRule <@ mult_d @>; 
              ruleengine.compilePatternToRule <@ log_d @>; 
              ruleengine.compilePatternToRule <@ exp_d @>; 
              ruleengine.compilePatternToRule <@ sin_d @>; 
              ruleengine.compilePatternToRule <@ cos_d @>; 
              ruleengine.compilePatternToRule <@ get_d @>;
              ruleengine.compilePatternToRule <@ length_d @>;
              ruleengine.compilePatternToRule <@ vbuild_d @>;
              //ruleengine.compilePatternToRule <@ sfold_d @>;
              fold_d;
              const_d;
              var_d; 
              chain_rule;
              //rules.lambdaAppToLet;
              ] 


let test_symdiff () = 
    printfn "symdiff: %A" (symdiff <@ fun (x: double) -> diff (1. * 2.) x @>)
    printfn "symdiff2: %A" (symdiff <@ fun (x: double) -> diff (let v = 1. * 2. in v) x @>)
    printfn "symdiff3: %A" (symdiff <@ fun (x: double) (y: double) (z: double) -> diff (let v = y * z in v) x @>)
    printfn "symdiff4: %A" (symdiff <@ fun (x: double) (y: double) (z: double) -> diff (let v = exp y in v) x @>)
    printfn "symdiff5: %A" (symdiff <@ fun (x: double) (y: double) (z: double) -> diff (let v = log z in v) x @>)
    printfn "symdiff6: %A" (symdiff <@ fun (x: double) (y: double) (z: double) -> diff (let v = sin z in v) x @>)
    printfn "symdiff7: %A" (symdiff <@ fun (x: double) (y: double) (z: double) -> diff (build (Card 10) (fun i -> y)) x @>)
    printfn "symdiff8: %A" (symdiff <@ fun (x: double) (y: Vector) (z: Vector) -> diff (build (Card 10) (fun i -> y.[i] + z.[i])) x @>)
    printfn "symdiff9: %A" (symdiff <@ fun (x: double) (y: Vector) (z: Vector) -> diff (foldOnRange (fun s i -> s * s) 0.0 (Card 0) (Card 10)) x @>)
    ()