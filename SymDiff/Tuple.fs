module Tuple

open NUnit.Framework
open Swensen.Unquote

type Tuple =
    static member get(tup:'T*'T, ind:int) = 
        match ind, tup with
        | 0, (a,_) -> a
        | 1, (_,b) -> b
        | _, _ -> failwith "unpack"
    static member get(tup:'T*'T*'T, ind:int) = 
        match ind, tup with
        | 0, (a,_,_) -> a
        | 1, (_,b,_) -> b
        | 2, (_,_,c) -> c
        | _, _ -> failwith "unpack"
    static member get(tup:'T*'T*'T*'T, ind:int) = 
        match ind, tup with
        | 0, (a,_,_,_) -> a
        | 1, (_,b,_,_) -> b
        | 2, (_,_,c,_) -> c
        | 3, (_,_,_,d) -> d
        | _, _ -> failwith "unpack"
    static member get(tup:'T*'T*'T*'T*'T, ind:int) = 
        match ind, tup with
        | 0, (a,_,_,_,_) -> a
        | 1, (_,b,_,_,_) -> b
        | 2, (_,_,c,_,_) -> c
        | 3, (_,_,_,d,_) -> d
        | 4, (_,_,_,_,e) -> e
        | _, _ -> failwith "unpack"
    static member get(tup:'T*'T*'T*'T*'T*'T, ind:int) = 
        match ind, tup with
        | 0, (a,_,_,_,_,_) -> a
        | 1, (_,b,_,_,_,_) -> b
        | 2, (_,_,c,_,_,_) -> c
        | 3, (_,_,_,d,_,_) -> d
        | 4, (_,_,_,_,e,_) -> e
        | 5, (_,_,_,_,_,f) -> f
        | _, _ -> failwith "unpack"
    static member get(tup:'T*'T*'T*'T*'T*'T*'T, ind:int) = 
        match ind, tup with
        | 0, (a,_,_,_,_,_,_) -> a
        | 1, (_,b,_,_,_,_,_) -> b
        | 2, (_,_,c,_,_,_,_) -> c
        | 3, (_,_,_,d,_,_,_) -> d
        | 4, (_,_,_,_,e,_,_) -> e
        | 5, (_,_,_,_,_,f,_) -> f
        | 6, (_,_,_,_,_,_,g) -> g
        | _, _ -> failwith "unpack"

[<Test>]
let test_Tuple() = 
    test <@ Tuple.get ((0,1,2,3,4,5),4) = 4 @>
    
