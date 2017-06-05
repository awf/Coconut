﻿module search

let nodeCostToString<'a> (printer: 'a -> string) (node: 'a) (cost: double) = 
  sprintf "exp: %s\ncost: %f\n" (printer node) cost

(* Utility methods *)
let nodesListToString<'a> (printer: 'a -> string) (list: ('a * double) List) : string = 
  String.concat "\n-------\n" (List.map (fun (e, c) -> nodeCostToString printer e c) list)

module Logging =
  type Reporter<'a> = 
    { 
      init: string -> unit; 
      step: int -> int -> int -> ('a * double) -> unit;  // Step#, Rule index, Rules#, NodeCost
      finish: ('a * double) list -> ('a * double) -> unit // All NodeCosts, Best NodeCost
    }
  
  type Logger = string -> unit
  
  let consoleLogger (enabled: bool) = fun (msg: string) ->
    if enabled then
      printfn "%s" msg

  let currentProcess() = System.Diagnostics.Process.GetCurrentProcess()
  
  let fileLogger (enabled: bool) (filename: string) = fun (msg: string) ->
    if enabled then
      //System.IO.File.AppendText(filename).WriteLine(sprintf "Time: %s, Memory: %d, Log Content\n: %s" (utils.currentTimeString()) (currentProcess().WorkingSet64) msg)
      let file = new System.IO.StreamWriter(filename,true)
      file.WriteLine(sprintf "Time: %s, Memory: %d, Log Content\n: %s" (utils.currentTimeString()) (currentProcess().WorkingSet64) msg)
      file.Close()
  
  let completeReporter<'a> (printer: 'a -> string) (logger: Logger) =
    { init = fun msg -> logger msg;
      step = fun stp ruleIdx rulesSize (node, cost) -> logger (sprintf "Step %d, rule %d out of %d: %s" stp ruleIdx rulesSize (nodeCostToString printer node cost))
      finish = fun allPrograms (node, cost) -> logger (sprintf "examined programs: %d\nBest: %s" (List.length allPrograms) (nodeCostToString printer node cost))
    }

open Logging

type SearchAlgorithm<'a> = Reporter<'a> -> 'a -> ('a -> 'a List) -> ('a -> double) -> ('a * double)

(* Breadth First Search Algorithm *)
let bfs<'a> (levels: int): SearchAlgorithm<'a> = fun (reporter: Reporter<'a>) (e: 'a) (children: 'a -> 'a List) (costModel: 'a -> double) -> 
  let range = [for i = 1 to levels do yield i]
  let revertedResult = 
    List.fold (fun acc cur ->  (List.collect (fun (exp, _) -> List.map (fun x -> x, costModel x) (children exp)) (List.head acc)) :: acc) [[e, costModel e]] range
  //if debug then
  //  let lines = 
  //    List.map (nodesListToString printer) (List.rev revertedResult)
  //  printfn "all children:\n%s\n*******" (String.concat "\n=======\n" lines)
  let allNodes = (List.concat revertedResult)
  let best = List.minBy snd allNodes
  reporter.finish allNodes best
  best

(* Random Walk *)
let randomWalk<'a> (levels: int): SearchAlgorithm<'a> = fun (reporter: Reporter<'a>)  (e: 'a)  (children: 'a -> 'a List) (costModel: 'a -> double) -> 
  reporter.init (sprintf "Random Walk started with %d levels" levels)
  let range = [for i = 1 to levels do yield i]
  let rand = new System.Random()
  let revertedResult = 
    List.fold (fun acc cur -> 
      let curNode = fst (List.head acc)
      let childNodes = children(curNode)
      if(childNodes.Length = 0) then 
        acc
      else 
        let index = rand.Next(childNodes.Length)
        //if debug then
        //  printfn "Chosen the rule #%d out of %d rules" index (childNodes.Length)
        
        let randomChild = childNodes.[index]
        let randomChildCost = costModel randomChild
        reporter.step cur index (childNodes.Length) (randomChild, randomChildCost)
        (randomChild, randomChildCost) :: acc) [e, costModel e] range
  //if debug then
  //  printfn "random expressions:\n%s\n" (nodesListToString printer (List.rev revertedResult))
  let best = List.minBy snd revertedResult
  reporter.finish revertedResult best
  best

exception CurrentListReturn of (double) list

(* Hill Climbing *)
let hillClimbing<'a> (levels: int): SearchAlgorithm<'a> = fun (reporter: Reporter<'a>)  (e: 'a)  (children: 'a -> 'a List) (costModel: 'a -> double) -> 
  reporter.init (sprintf "Hill Climbing started with %d levels" levels)
  let range = [for i = 1 to levels do yield i]
  let mutable currentBest = e
  let mutable currentBestCost = costModel e
  
  let revertedResult = 
    try
      List.fold (fun acc cur -> 
        let curNode = fst (List.head acc)
        let childNodes = children(curNode)
        if(childNodes.Length = 0) then 
          raise (CurrentListReturn (acc |> List.map snd))
        else 
          let (index, bestChild, bestChildCost) = childNodes |> List.mapi (fun idx n -> idx, n, costModel n) |> List.minBy (fun (_,_,c) -> c)
          reporter.step cur index (childNodes.Length) (bestChild, bestChildCost)
          if(bestChildCost < currentBestCost) then
            currentBestCost <- bestChildCost
            currentBest <- bestChild
          else
            raise (CurrentListReturn (acc |> List.map snd))
          (bestChild, bestChildCost) :: acc) [e, costModel e] range
    with
       | CurrentListReturn costs -> costs |> List.map (fun x -> e, x)
  let best = (currentBest, currentBestCost)
  reporter.finish revertedResult best
  best


(* Simulated Annealing *)
let simulatedAnnealing<'a> (levels: int): SearchAlgorithm<'a> = fun (reporter: Reporter<'a>)  (e: 'a)  (children: 'a -> 'a List) (costModel: 'a -> double) -> 
  reporter.init (sprintf "Simulated Annealing started with %d levels" levels)
  let range = [for i = 1 to levels do yield i]
  let mutable currentBest = e
  let mutable currentBestCost = costModel e
  let mutable temprature = 2.0 * currentBestCost

  let rand = new System.Random()
  
  let revertedResult = 
      List.fold (fun acc cur -> 
        let (curNode, curCost) = (List.head acc)
        let childNodes = children(curNode)
        if(childNodes.Length = 0) then 
          failwithf "No more children for %A" curNode
        else 
          let index = rand.Next(childNodes.Length)
        
          let randomChild = childNodes.[index]
          let randomChildCost = costModel randomChild
          let delta = randomChildCost - curCost
          reporter.step cur index (childNodes.Length) (randomChild, randomChildCost)
          let (nextChild, nextChildCost) = 
            if(delta < 0.0) then
              if(randomChildCost < currentBestCost) then
                currentBestCost <- randomChildCost
                currentBest <- randomChild
              (randomChild, randomChildCost)
            else
              if (rand.NextDouble() < System.Math.Pow(System.Math.E, (-delta) / temprature)) then
                (randomChild, randomChildCost)
              else
                (curNode, curCost)
          temprature <- temprature * 0.95
          (nextChild, nextChildCost) :: acc) [e, costModel e] range
  let best = (currentBest, currentBestCost)
  reporter.finish revertedResult best
  best