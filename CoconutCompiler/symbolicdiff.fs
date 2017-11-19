module symbolicdiff

open corelang
open rules_d
open FSharp.Quotations
open phase_based_optimizer
open types
open ccodegen

let symdiff (rs: ruleengine.Rule list) (exp: Expr): Expr = 
  exp
    |> trans (rs @ [ruleengine.compilePatternToRule <@ add_d @>;
              ruleengine.compilePatternToRule <@ sub_d @>;
              ruleengine.compilePatternToRule <@ mult_d @>; 
              ruleengine.compilePatternToRule <@ div_d @>; 
              ruleengine.compilePatternToRule <@ log_d @>; 
              ruleengine.compilePatternToRule <@ exp_d @>; 
              ruleengine.compilePatternToRule <@ sin_d @>; 
              ruleengine.compilePatternToRule <@ cos_d @>; 
              ruleengine.compilePatternToRule <@ tan_d @>; 
              ruleengine.compilePatternToRule <@ sqrt_d @>; 
              ruleengine.compilePatternToRule <@ cast_in_d @>; 
              ruleengine.compilePatternToRule <@ cast_ci_d @>; 
              ruleengine.compilePatternToRule <@ int_d @>; 
              ruleengine.compilePatternToRule <@ vget_d @>;
              ruleengine.compilePatternToRule <@ mget_d @>;
              ruleengine.compilePatternToRule <@ m3get_d @>;
              ruleengine.compilePatternToRule <@ vlength_d @>;
              ruleengine.compilePatternToRule <@ mlength_d @>;
              ruleengine.compilePatternToRule <@ m3length_d @>;
              build_d;
              array_d;
              letFold_d;
              fold_d;
              card_d;
              const_d;
              nondouble_d;
              var_d; 
              //letIf_d;
              if_d;
              chain_rule;
              lambda_d;
              mio_d;
              //rules.lambdaAppToLet;
              ])

let transformDiff (rs: ruleengine.Rule list) (e: Expr): Expr = 
  let (inputs, body) = match e with transformer.TopLevelFunction (i, b) -> (i, b)
  let inputsd = inputs |> List.map MakeDVar
  let diffBody = Diff body (Expr.Var(new Var("dx", typeof<Number>)))
  transformer.LambdaN(List.append inputs inputsd, diffBody |> symdiff rs)

let compileD (opt: bool) (moduleName: string) (methodName: string): string = 
     printf "compile [d]%s.%s: " moduleName methodName
     let expr = compiler.getMethodExpr moduleName methodName
     let e = expr |> transformDiff []
     let optimized = if opt then e else e // TODO
     let debug = false
     if(debug) then 
       printfn "/* Original code:\n%A\n*/\n" (prettyprint e)
       if(opt) then 
         printfn "/* Optimized code:\n%A\n*/\n" (prettyprint optimized)
     let functionName = transformer.methodVariableName methodName moduleName
     let s = (
               printf "C"
               ccodegenTopLevel optimized (diffName functionName) debug)
     printfn " done"
     s

let compileModuleD (moduleName: string) (dependentModules: string List) (opt: bool): unit = 
  let depModulesD = dependentModules |> List.map diffName
  compiler.compileModuleGeneric moduleName (moduleName :: depModulesD) diffName (compileD opt)

let test_symdiff () = 
    utils.variable_counter <- 1000
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
    //compiler.compileModule "linalg" [] false false
    //compiler.compileModule "usecases_gmm" ["linalg"] false false
    //let vectorAdd3 = compiler.getMethodExpr "linalg" "vectorAdd3" |> fusion_optimize |> transformDiff |> fusion_optimize |> fscodegen.fscodegenTopLevel
    //printfn "symdiff vadd3: %A" vectorAdd3
    //let dot_prod = compiler.getMethodExpr "linalg" "dot_prod" |> fusion_optimize |> transformDiff |> fusion_optimize |> fscodegen.fspreprocess |> trans [rules_old.letCSE] |> fscodegen.fscodegenTopLevel
    //printfn "symdiff vdot: %A" dot_prod
    //let matSlice = compiler.getMethodExpr "linalg" "vectorFoldNumber" |> transformDiff |> ctransformer.closureConversion |> ctransformer.anfConversion false  |> fscodegen.fscodegenTopLevel
    //printfn "symdiff matSlice: %A" matSlice
    compileModuleD "linalg" [] false
    compileModuleD "usecases_gmm" ["linalg"] false
    compileModuleD "usecases_ba" ["linalg"] false
    let optimizeD moduleName methodName finalName = 
      compiler.getMethodExpr moduleName methodName 
        |> fusion_optimize 
        |> trans [rules_old.letCommutingConversion_old; rules_old.letNormalization_old; rules.foldUnroll]
        //|> ctransformer.anfConversion false 
        |> ctransformer.fullAnfConversion
        |> transformDiff [letIf_d]
        |> fusion_optimize 
        |> trans [rules.foldPartiallyDCE] 
        //|> fscodegen.fspreprocess 
        |> ctransformer.fullAnfConversion
        |> trans [rules_old.letCommutingConversion_old; rules_old.letNormalization_old]
        |> trans [rules_old.dce_old]
        |> trans [rules_old.letCSE] 

        |> (fun p -> storagedtransformer.transformStoraged p transformer.EMPTY_STORAGE Map.empty)
        |> storagedtransformer.getAliasSimplify
        |> storagedtransformer.simplifyStoraged 
        |> trans [rules_old.letCommutingConversion_old; rules_old.letNormalization_old]
        |> trans [rules_old.dce_old]

        //|> fscodegen.fscodegenTopLevel
        |> (fun e -> ccodegenTopLevel e finalName true)
    let res = 
      //optimizeD "usecases_gmm" "gmm_objective" "gmm_obj_opt"
      optimizeD "usecases_ba" "project" "project_d"
      //optimizeD "linalg" "dot_prod" "dot_prod_d"
    printfn "symdiff: %s" res
    ()