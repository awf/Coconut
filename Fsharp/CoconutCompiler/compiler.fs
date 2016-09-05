module compiler 

open Microsoft.FSharp.Quotations
open transformer
open ccodegen
open ctransformer
open optimizer

let getMethodExpr (moduleName: string) (methodName: string): Expr = 
  let methodInfo = assembly.GetType(moduleName).GetMethod(methodName)
  let reflDefnOpt = Microsoft.FSharp.Quotations.Expr.TryGetReflectedDefinition(methodInfo)
  match reflDefnOpt with
   | None -> failwith (sprintf "%s failed. It seems you forgot to use [<ReflectedDefinition>]." methodName)
   | Some(e) -> e

(* The entry point for the compiler which invokes different phases and code generators *)
let compile (moduleName: string) (methodName: string) (opt: bool) (storaged: bool): string = 
     let e = getMethodExpr moduleName methodName
     let optimized = 
       if(opt) then 
         let optimized = Seq.isEmpty (assembly.GetType(moduleName).GetMethod(methodName).GetCustomAttributes(typeof<types.DontOptimize>, true))
         if(optimized) then
           optimize e 
         else 
           e
       else 
         e
     let debug = true
     if(debug) then 
       printfn "/* Oringinal code:\n%A\n*/\n" (prettyprint e)
       if(opt) then 
         printfn "/* Optimized code:\n%A\n*/\n" (prettyprint optimized)
     let functionName = methodVariableName methodName moduleName
     let generatedCode = 
       ccodegenTopLevel optimized functionName debug
       //""
     let generatedStoragedCode = 
       if storaged then
         let se = 
           storagedtransformer.transformStoraged optimized storagedtransformer.EMPTY_STORAGE Map.empty
           |> storagedtransformer.simplifyStoraged
         let sFunctionName = storagedtransformer.storagedName functionName
         let ce = cardinfer.inferCardinality optimized Map.empty
         let cFunctionName = cardinfer.cardName functionName
         ccodegenTopLevel ce cFunctionName debug +
           ccodegenTopLevel se sFunctionName debug
       else
         ""
     generatedCode + generatedStoragedCode

let compileSeveral (moduleName: string) (methodNames: string List) (opt: bool) (storaged: bool) =
  List.map (fun m -> 
    existingMethods <- (moduleName, m) :: existingMethods
    compile moduleName m opt storaged
  ) methodNames


let compileModule (moduleName: string) (dependentModules: string List) (opt: bool) (storaged: bool) = 
  let methods = List.map (fun (x: System.Reflection.MethodInfo) -> x.Name) 
                  (List.filter (fun (x: System.Reflection.MethodInfo) -> 
                    x.DeclaringType.Name = moduleName) 
                    (List.ofArray (assembly.GetType(moduleName).GetMethods())))
  let nameWithPostfix name = if storaged then sprintf "%s_storaged" name else name
  let generatedMethods = compileSeveral moduleName methods opt storaged
  let moduleNameWithPostfix = nameWithPostfix moduleName
  let depModulesString = dependentModules |> List.map nameWithPostfix |> List.map (fun m -> sprintf "#include \"%s.h\"" m) 
  let moduleMacroName = sprintf "__%s_H__" (moduleNameWithPostfix.ToUpper())
  let fileName = sprintf "%s.h" moduleNameWithPostfix
  let header = sprintf """#ifndef %s 
#define %s 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>""" moduleMacroName moduleMacroName
  let footer = "#endif"
  System.IO.File.WriteAllLines 
    ("../../coconut/" + fileName, 
      List.append (header :: (List.append depModulesString generatedMethods)) ([footer]))
  ()
