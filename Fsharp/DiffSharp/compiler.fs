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
let compile (moduleName: string) (methodName: string) (opt: bool): string = 
     let e = getMethodExpr moduleName methodName
     let optimized = if(opt) then optimize e else e
     //printfn "/* Oringinal code:\n%A\n*/\n" (prettyprint e)
     //if(opt) then printfn "/* Optimized code:\n%A\n*/\n" (prettyprint optimized)
     let preprocessed = cpreprocess optimized
     //printfn "/* Preprocessed code:\n%A\n*/\n" (prettyprint preprocessed)
     let generated = ccodegenFunction preprocessed (moduleName + "_" + methodName) false
     //printfn "// Generated C code for %s.%s:\n\n%s" moduleName methodName generated
     generated

let compileSeveral (moduleName: string) (methodNames: string List) (opt: bool) =
  List.map (fun m -> 
    existingMethods <- (moduleName, m) :: existingMethods
    compile moduleName m opt
  ) methodNames


let compileModule (moduleName: string) (dependentModules: string List) (opt: bool) = 
  let methods = List.map (fun (x: System.Reflection.MethodInfo) -> x.Name) 
                  (List.filter (fun (x: System.Reflection.MethodInfo) -> 
                    x.DeclaringType.Name = moduleName) 
                    (List.ofArray (assembly.GetType(moduleName).GetMethods())))
  let generatedMethods = compileSeveral moduleName methods opt
  let depModulesString = List.map (fun m -> sprintf "#include \"%s.h\"" m) dependentModules
  let moduleMacroName = sprintf "__%s_H__" (moduleName.ToUpper())
  let header = sprintf """#ifndef %s 
#define %s 
#include "runtime/fsharp.h"
#include <stdio.h>
#include <math.h>""" moduleMacroName moduleMacroName
  let footer = "#endif"
  System.IO.File.WriteAllLines 
    ("../../coconut/" + moduleName + ".h", 
      List.append (header :: (List.append depModulesString generatedMethods)) ([footer]))
  ()