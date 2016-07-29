module search

(* Utility methods *)
let nodesListToString<'a> (printer: 'a -> string) (list: ('a * double) List) : string = 
  String.concat "\n-------\n" (List.map (fun (e, c) -> sprintf "exp: %s\ncost: %f\n" (printer e) c) list)

(* Breadth First Search Algorithm *)
let bfs<'a> (e: 'a) (levels: int) (children: 'a -> 'a List) (costModel: 'a -> double) (debug: bool) (printer: 'a -> string): ('a * double) = 
  let range = [for i = 1 to levels do yield i]
  let revertedResult = 
    List.fold (fun acc cur ->  (List.collect (fun (exp, _) -> List.map (fun x -> x, costModel x) (children exp)) (List.head acc)) :: acc) [[e, costModel e]] range
  if debug then
    let lines = 
      List.map (nodesListToString printer) (List.rev revertedResult)
    printfn "all children:\n%s\n*******" (String.concat "\n=======\n" lines)
  printfn "examined programs: %d" (List.length (List.concat revertedResult))
  List.minBy snd (List.concat revertedResult)

(* Random Walk *)
let randomWalk<'a> (e: 'a) (levels: int) (children: 'a -> 'a List) (costModel: 'a -> double) (debug: bool) (printer: 'a -> string): ('a * double) = 
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
        if debug then
          printfn "Chosen the rule #%d out of %d rules" index (childNodes.Length)
        let randomChild = childNodes.[index]
        (randomChild, costModel randomChild) :: acc) [e, costModel e] range
  if debug then
    printfn "random expressions:\n%s\n" (nodesListToString printer (List.rev revertedResult))
  List.minBy snd revertedResult