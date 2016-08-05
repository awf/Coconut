module search

let nodeCostToString<'a> (printer: 'a -> string) (node: 'a) (cost: double) = 
  sprintf "exp: %s\ncost: %f\n" (printer node) cost

(* Utility methods *)
let nodesListToString<'a> (printer: 'a -> string) (list: ('a * double) List) : string = 
  String.concat "\n-------\n" (List.map (fun (e, c) -> nodeCostToString printer e c) list)

type Reporter<'a> = 
  { 
    init: unit -> unit; 
    step: int -> int -> ('a * double) -> unit;  // Step#, Rule#, NodeCost
    finish: ('a * double) list -> ('a * double) -> unit // All NodeCosts, Best NodeCost
  }

type Logger = string -> unit

let consoleLogger (enabled: bool) = fun (msg: string) ->
  if enabled then
    printfn "%s" msg

let completeReporter<'a> (printer: 'a -> string) (logger: Logger) =
  { init = fun () -> ();
    step = fun stp ruleIdx (node, cost) -> logger (sprintf "Step %d, rule %d: %s" stp ruleIdx (nodeCostToString printer node cost))
    finish = fun allPrograms (node, cost) -> logger (sprintf "examined programs: %d\nBest: %s" (List.length allPrograms) (nodeCostToString printer node cost))
  }

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
        reporter.step cur index (randomChild, randomChildCost)
        (randomChild, randomChildCost) :: acc) [e, costModel e] range
  //if debug then
  //  printfn "random expressions:\n%s\n" (nodesListToString printer (List.rev revertedResult))
  let best = List.minBy snd revertedResult
  reporter.finish revertedResult best
  best