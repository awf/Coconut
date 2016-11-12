module ba_opt

open corelang

let project = fun (cam: double[]) (x: double[]) -> 
  let sqtheta212 = (
    linalg.iterateNumber (fun acc idx -> 
      let acc0 = (
        acc) in 
      let i = (
        idx) in 
      let x1 = (
        cam.[i]) in 
      let cur = (
        ((x1) * (x1))) in 
      ((acc0) + (cur))) (0.000000) (Card(0)) (Card(2))) in 
  let Xcam270 = (
    if(((sqtheta212) <> (0.000000))) then 
      let theta213 = (
        sqrt(sqtheta212)) in 
      let costheta214 = (
        cos(theta213)) in 
      let sintheta215 = (
        sin(theta213)) in 
      let theta_inv216 = (
        ((1.000000) / (theta213))) in 
      let xi217 = (
        cam.[1]) in 
      let x218 = (
        x.[2]) in 
      let y219 = (
        cam.[5]) in 
      let xi220 = (
        cam.[2]) in 
      let x221 = (
        x.[1]) in 
      let y222 = (
        cam.[4]) in 
      let xi223 = (
        cam.[2]) in 
      let x224 = (
        x.[0]) in 
      let y225 = (
        cam.[3]) in 
      let xi226 = (
        cam.[0]) in 
      let x227 = (
        x.[2]) in 
      let y228 = (
        cam.[5]) in 
      let xi229 = (
        cam.[0]) in 
      let x230 = (
        x.[1]) in 
      let y231 = (
        cam.[4]) in 
      let xi232 = (
        cam.[1]) in 
      let x233 = (
        x.[0]) in 
      let y234 = (
        cam.[3]) in 
      let w_cross_X235 = (
        [| (* Array of type System.Double *) 
          ((((((xi217) * (theta_inv216))) * (((x218) - (y219))))) - (((((xi220) * (theta_inv216))) * (((x221) - (y222))))));
          ((((((xi223) * (theta_inv216))) * (((x224) - (y225))))) - (((((xi226) * (theta_inv216))) * (((x227) - (y228))))));
          ((((((xi229) * (theta_inv216))) * (((x230) - (y231))))) - (((((xi232) * (theta_inv216))) * (((x233) - (y234)))))) |]) in 
      let tmp242 = (
        ((linalg.iterateNumber (fun acc idx -> 
          let acc0 = (
            acc) in 
          let i = (
            idx) in 
          let xi236 = (
            cam.[i]) in 
          let x237 = (
            ((xi236) * (theta_inv216))) in 
          let x238 = (
            x.[i]) in 
          let y239 = (
            cam.[((i) + (3))]) in 
          let y240 = (
            ((x238) - (y239))) in 
          let cur = (
            ((x237) * (y240))) in 
          ((acc0) + (cur))) (0.000000) (Card(0)) (Card(2))) * (((1.000000) - (costheta214))))) in 
      corelang.build (corelang.length (x)) (fun i -> 
//      [|for i = 0 to (x.Length - 1) do 
//        yield (
          let x243 = (
            x.[i]) in 
          let y244 = (
            cam.[((i) + (3))]) in 
          let xi245 = (
            ((x243) - (y244))) in 
          let x246 = (
            ((xi245) * (costheta214))) in 
          let xi247 = (
            w_cross_X235.[i]) in 
          let y248 = (
            ((xi247) * (sintheta215))) in 
          let x249 = (
            ((x246) + (y248))) in 
          let xi250 = (
            cam.[i]) in 
          let xi251 = (
            ((xi250) * (theta_inv216))) in 
          let y252 = (
            ((xi251) * (tmp242))) in 
          ((x249) + (y252)))
    else 
      let x253 = (
        x.[2]) in 
      let y254 = (
        cam.[5]) in 
      let x255 = (
        x.[1]) in 
      let y256 = (
        cam.[4]) in 
      let x257 = (
        x.[0]) in 
      let y258 = (
        cam.[3]) in 
      let x259 = (
        x.[2]) in 
      let y260 = (
        cam.[5]) in 
      let x261 = (
        x.[1]) in 
      let y262 = (
        cam.[4]) in 
      let x263 = (
        x.[0]) in 
      let y264 = (
        cam.[3]) in 
      let y265 = (
        [| (* Array of type System.Double *) 
          ((((cam.[1]) * (((x253) - (y254))))) - (((cam.[2]) * (((x255) - (y256))))));
          ((((cam.[2]) * (((x257) - (y258))))) - (((cam.[0]) * (((x259) - (y260))))));
          ((((cam.[0]) * (((x261) - (y262))))) - (((cam.[1]) * (((x263) - (y264)))))) |]) in 
      corelang.build (corelang.length (x)) (fun i -> 
//      [|for i = 0 to (x.Length - 1) do 
//        yield (
          let x266 = (
            x.[i]) in 
          let y267 = (
            cam.[((i) + (3))]) in 
          let x268 = (
            ((x266) - (y267))) in 
          let y269 = (
            y265.[i]) in 
          ((x268) + (y269)))) in 
  let y271 = (
    ((1.000000) / (Xcam270.[2]))) in 
  let rsq275291 = (
    linalg.iterateNumber (fun acc idx -> 
      let acc0 = (
        acc) in 
      let i = (
        idx) in 
      let xi272 = (
        Xcam270.[i]) in 
      let x1273 = (
        ((xi272) * (y271))) in 
      let cur = (
        ((x1273) * (x1273))) in 
      ((acc0) + (cur))) (0.000000) (Card(0)) (Card(1))) in 
  let L276292 = (
    ((((1.000000) + (((cam.[9]) * (rsq275291))))) + (((((cam.[10]) * (rsq275291))) * (rsq275291))))) in 
  let y277293 = (
    cam.[6]) in 
//  [|for i = 0 to (2 - 1) do 
//    yield (
  corelang.build (Card(2)) (fun i -> 
      let x278294 = (
        cam.[((i) + (7))]) in 
      let xi279295 = (
        Xcam270.[i]) in 
      let xi280296 = (
        ((xi279295) * (y271))) in 
      let xi281297 = (
        ((xi280296) * (L276292))) in 
      let y282298 = (
        ((xi281297) * (y277293))) in 
      ((x278294) + (y282298)))

