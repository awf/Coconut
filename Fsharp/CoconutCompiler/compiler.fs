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
     let debug = false
     if(debug) then 
       printfn "/* Oringinal code:\n%A\n*/\n" (prettyprint e)
       if(opt) then 
         printfn "/* Optimized code:\n%A\n*/\n" (prettyprint optimized)
     let functionName = methodVariableName methodName moduleName
     if storaged then
       let se = 
         storagedtransformer.transformStoraged optimized transformer.EMPTY_STORAGE Map.empty
       let sse = storagedtransformer.simplifyStoraged se
       let sFunctionName = storagedtransformer.storagedName functionName
       let ce = cardinfer.inferCardinality optimized Map.empty
       let sce = cardinfer.simplifyCardinality ce
       if(debug) then 
         printfn "/* Storaged code:\n%A\n*/\n" (prettyprint se)
         printfn "/* Simplified Storaged code:\n%A\n*/\n" (prettyprint sse)
       let cFunctionName = cardinfer.cardName functionName
       ccodegenTopLevel sce cFunctionName debug + "\n\n" + 
         ccodegenTopLevel sse sFunctionName debug
     else
       ccodegenTopLevel optimized functionName debug

let compileSeveral (moduleName: string) (methodNames: string List) (opt: bool) (storaged: bool) =
  List.map (fun m -> 
    existingMethods <- (moduleName, m) :: existingMethods
    compile moduleName m opt storaged
  ) methodNames

let compileToHeaderFile (headerName: string) (dependentHeaders: string List) (content: string List): unit =
  let depModulesString = dependentHeaders |> List.map (fun m -> sprintf "#include \"%s.h\"" m) 
  let moduleMacroName = sprintf "__%s_H__" (headerName.ToUpper())
  let fileName = sprintf "%s.h" headerName
  let header = sprintf """#ifndef %s 
#define %s 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>""" moduleMacroName moduleMacroName
  let footer = "#endif"
  System.IO.File.WriteAllLines 
    ("../../C/" + fileName, 
      List.append (header :: (List.append depModulesString content)) ([footer]))
  ()


let compileModule (moduleName: string) (dependentModules: string List) (opt: bool) (storaged: bool): unit = 
  let methods = List.map (fun (x: System.Reflection.MethodInfo) -> x.Name) 
                  (List.filter (fun (x: System.Reflection.MethodInfo) -> 
                    x.DeclaringType.Name = moduleName) 
                    (List.ofArray (assembly.GetType(moduleName).GetMethods())))
  let nameWithPostfix name = if storaged then sprintf "%s_storaged" name else name
  let generatedMethods = compileSeveral moduleName methods opt storaged
  let moduleNameWithPostfix = nameWithPostfix moduleName
  let depModulesString = dependentModules |> List.map nameWithPostfix
  compileToHeaderFile moduleNameWithPostfix depModulesString generatedMethods
