﻿module compiler 

open Microsoft.FSharp.Quotations
open transformer
open ccodegen
open ctransformer
open optimizer

let getMethodExpr (moduleName: string) (methodName: string): Expr = 
  let methodInfo = currentAssembly.GetType(moduleName).GetMethod(methodName)
  let body = methodInfo.GetMethodBody()
  let reflDefnOpt = Microsoft.FSharp.Quotations.Expr.TryGetReflectedDefinition(methodInfo)
  match reflDefnOpt with
   | None -> failwith (sprintf "%s failed. It seems you forgot to use [<ReflectedDefinition>]." methodName)
   | Some(e) -> e

(* The entry point for the compiler which invokes different phases and code generators *)
let compile (moduleName: string) (methodName: string) (opt: bool) (storaged: bool): string = 
     printf "compile %s%s.%s: " (if opt then "[optimized] " else "") moduleName methodName
     let e = getMethodExpr moduleName methodName
     let optimized = 
       if(opt) then 
         let optimized = Seq.isEmpty (currentAssembly.GetType(moduleName).GetMethod(methodName).GetCustomAttributes(typeof<types.DontOptimize>, true))
         if(optimized) then
           printf "O"
           optimize e 
         else 
           e
       else 
         e
     let debug = false
     if(debug) then 
       printfn "/* Original code:\n%A\n*/\n" (prettyprint e)
       if(opt) then 
         printfn "/* Optimized code:\n%A\n*/\n" (prettyprint optimized)
     let functionName = methodVariableName methodName moduleName
     let s = (if storaged then
               printf "S"
               let se = 
                 storagedtransformer.transformStoraged optimized transformer.EMPTY_STORAGE Map.empty
               let sse = storagedtransformer.simplifyStoraged se
               let sFunctionName = storagedtransformer.storagedName functionName
               let ce = cardinfer.inferCardinality optimized Map.empty
               let sce = cardinfer.simplifyCardinality ce
               if(debug) then 
                 printfn "/* Storaged code:\n%A\n*/\n" (prettyprint se)
                 printfn "/* Simplified Storaged code:\n%A\n*/\n" (prettyprint sse)
                 printfn "/* Cardinality code:\n%A\n*/\n" (prettyprint ce)
                 printfn "/* Simplified Cardinality code:\n%A\n*/\n" (prettyprint sce)
               let cFunctionName = cardinfer.cardName functionName
               printf "C"
               ccodegenTopLevel sce cFunctionName debug + "\n\n" + ccodegenTopLevel sse sFunctionName debug
             else
               printf "C"
               ccodegenTopLevel optimized functionName debug)
     printfn " done"
     s

let compileSeveral (moduleName: string) (methodNames: string List) (opt: bool) (storaged: bool) =
  List.map (fun m -> 
    existingMethods <- (moduleName, m) :: existingMethods
    compile moduleName m opt storaged
  ) methodNames

let writeToHeaderFile (headerName: string) (dependentHeaders: string List) (content: string List): unit =
  let depModulesString = dependentHeaders |> List.map (fun m -> sprintf "#include \"%s.h\"" m) 
  let moduleMacroName = sprintf "__%s_H__" (headerName.ToUpper())
  let fileName = sprintf "%s.h" headerName
  let header = sprintf """#ifndef %s 
#define %s 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>""" moduleMacroName moduleMacroName
  let footer = "#endif"
  System.IO.File.WriteAllLines 
    ("../../../outputs/C/" + fileName, 
      List.append (header :: (List.append depModulesString content)) ([footer]))
  ()

let compileModule (moduleName: string) (dependentModules: string List) (opt: bool) (storaged: bool): unit = 
  let allMethods = 
    let moduleInfo = currentAssembly.GetType(moduleName)
    moduleInfo.GetMethods() |> List.ofArray
  let methods = 
    allMethods |> List.filter (fun (x: System.Reflection.MethodInfo) -> x.DeclaringType.Name = moduleName) 
               |> List.map (fun (x: System.Reflection.MethodInfo) -> x.Name) 
  let nameWithPostfix name = if storaged then sprintf "%s_storaged" name else name
  let moduleNameWithPostfix = nameWithPostfix moduleName
  printf "Compiling %s.fs [%d methods] to %s.h\n" moduleName (methods.Length) moduleNameWithPostfix 
  let generatedMethods = compileSeveral moduleName methods opt storaged
  let depModulesString = dependentModules |> List.map nameWithPostfix
  writeToHeaderFile moduleNameWithPostfix depModulesString generatedMethods

open FSharp.Compiler.CodeDom
open System.CodeDom.Compiler

let compileModuleFromSource (moduleName: string) (dependentModules: string List) (folder: string) (opt: bool) (storaged: bool): unit = 
    let provider = new FSharpCodeProvider()
    let compiler = provider.CreateCompiler()
    let parameters = new CompilerParameters(GenerateExecutable = false, OutputAssembly = "tmp.dll")
    let fsmoothRuntimeAssembly = System.Reflection.Assembly.GetAssembly(typeof<types.Storage>).Location;
    let timerAssembly = System.Reflection.Assembly.GetAssembly(typeof<types.Timer>).Location;
    parameters.ReferencedAssemblies.Add(fsmoothRuntimeAssembly)
    parameters.ReferencedAssemblies.Add(timerAssembly)
    let fileNames = (moduleName :: dependentModules) |> List.map (fun s -> sprintf "../../../%s/%s.fs" folder s) |> List.rev
    let results = compiler.CompileAssemblyFromFileBatch(parameters, fileNames |> List.toArray)
    if results.Errors.HasErrors then
        failwithf "Compilation Failed for %s with %A" moduleName results.Errors
    currentAssembly <- results.CompiledAssembly
    compileModule moduleName dependentModules opt storaged