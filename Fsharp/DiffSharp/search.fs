module search

(* Breadth First Search Algorithm *)
let bfs<'a> (e: 'a) (levels: int) (children: 'a -> 'a List) (costModel: 'a -> double) (debug: bool) (printer: 'a -> string): ('a * double) = 
  let range = [for i = 1 to levels do yield i]
  let revertedResult = 
    List.fold (fun acc cur ->  (List.collect (fun (exp, _) -> List.map (fun x -> x, costModel x) (children exp)) (List.head acc)) :: acc) [[e, costModel e]] range
  if debug then
    let lines = 
      List.map (fun list ->
        String.concat "\n-------\n" (List.map (fun (e, c) -> sprintf "exp: %s\ncost: %f\n" (printer e) c) list)) (List.rev revertedResult)
    printfn "all children:\n%s\n*******" (String.concat "\n=======\n" lines)
  List.minBy snd (List.concat revertedResult)
