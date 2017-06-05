module symbolicdiff

open corelang
open rules_d
open FSharp.Quotations
open phase_based_optimizer
open types

let symdiff (exp: Expr): Expr = 
  exp
    |> trans [ruleengine.compilePatternToRule <@ add_d @>;
              ruleengine.compilePatternToRule <@ sub_d @>;
              ruleengine.compilePatternToRule <@ mult_d @>; 
              ruleengine.compilePatternToRule <@ log_d @>; 
              ruleengine.compilePatternToRule <@ exp_d @>; 
              ruleengine.compilePatternToRule <@ sin_d @>; 
              ruleengine.compilePatternToRule <@ cos_d @>; 
              ruleengine.compilePatternToRule <@ vget_d @>;
              ruleengine.compilePatternToRule <@ mget_d @>;
              ruleengine.compilePatternToRule <@ vlength_d @>;
              ruleengine.compilePatternToRule <@ mlength_d @>;
              ruleengine.compilePatternToRule <@ vbuild_d @>;
              ruleengine.compilePatternToRule <@ mbuild_d @>;
              //ruleengine.compilePatternToRule <@ sfold_d @>;
              fold_d;
              const_d;
              var_d; 
              if_d;
              chain_rule;
              //rules.lambdaAppToLet;
              ] 

let transformDiff (e: Expr): Expr = 
  let (inputs, body) = match e with transformer.TopLevelFunction (i, b) -> (i, b)
  let inputsd = inputs |> List.map MakeDVar
  let diffBody = Diff body (Expr.Var(new Var("dx", typeof<Number>)))
  transformer.LambdaN(List.append inputs inputsd, diffBody |> symdiff)

let test_symdiff () = 
    //printfn "symdiff: %A" (symdiff <@ fun (x: double) -> diff (1. * 2.) x @>)
    //printfn "symdiff2: %A" (symdiff <@ fun (x: double) -> diff (let v = 1. * 2. in v) x @>)
    //printfn "symdiff3: %A" (symdiff <@ fun (x: double) (y: double) (z: double) -> diff (let v = y * z in v) x @>)
    //printfn "symdiff4: %A" (symdiff <@ fun (x: double) (y: double) (z: double) -> diff (let v = exp y in v) x @>)
    //printfn "symdiff5: %A" (symdiff <@ fun (x: double) (y: double) (z: double) -> diff (let v = log z in v) x @>)
    //printfn "symdiff6: %A" (symdiff <@ fun (x: double) (y: double) (z: double) -> diff (let v = sin z in v) x @>)
    //printfn "symdiff7: %A" (symdiff <@ fun (x: double) (y: double) (z: double) -> diff (build (Card 10) (fun i -> y)) x @>)
    //printfn "symdiff8: %A" (symdiff <@ fun (x: double) (y: Vector) (z: Vector) -> diff (build (Card 10) (fun i -> y.[i] + z.[i])) x @>)
    //printfn "symdiff9: %A" (symdiff <@ fun (x: double) (y: Vector) (z: Vector) -> diff (foldOnRange (fun s i -> s * s) 0.0 (Card 0) (Card 10)) x @>)
    //printfn "symdiff10: %A" (symdiff <@ fun (x: double) (y: Vector) (z: Vector) -> diff (foldOnRange (fun s i -> build (length s) (fun i -> s.[i])) z (Card 0) (Card 10)) x @>)
    compiler.compileModule "linalg" [] false false
    let vectorAdd3 = compiler.getMethodExpr "linalg" "vectorAdd3" |> fusion_optimize |> transformDiff |> fusion_optimize |> fscodegen.fscodegenTopLevel
    printfn "symdiff vadd3: %A" vectorAdd3
    let dot_prod = compiler.getMethodExpr "linalg" "dot_prod" |> fusion_optimize |> transformDiff |> fusion_optimize |> fscodegen.fscodegenTopLevel
    printfn "symdiff vdot: %A" dot_prod
    //compiler.compileModule "usecases_gmm" ["linalg"] false false
    //let gmm = compiler.getMethodExpr "usecases_gmm" "gmm_objective" |> fusion_optimize |> transformDiff |> fusion_optimize |> fscodegen.fscodegenTopLevel
    //printfn "symdiff gmm: %A" gmm
    ()