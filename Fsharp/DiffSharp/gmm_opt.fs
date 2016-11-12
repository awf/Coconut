module gmm_opt

open corelang

let gmm_objective (x:Matrix) (alphas:Vector) (means:Matrix) (qs:Matrix) (ls:Matrix) (wishart_gamma:Number) (wishart_m:Number) =
  let n = (
    corelang.length (x)) in 
  let K = (
    corelang.length (alphas)) in 
  let mx = (
    corelang.fold (fun acc cur -> 
      if(((acc) > (cur))) then 
        acc
      else 
        cur) (-1000.000000) (alphas)) in 
  let semx174 = (
    linalg.iterateNumber (fun acc idx -> 
      let acc0 = (
        acc) in 
      let i = (
        idx) in 
      let x0 = (
        alphas.[i]) in 
      let cur = (
        exp(((x0) - (mx)))) in 
      ((acc0) + (cur))) (0.000000) (Card(0)) (((corelang.length (alphas)) .- (Card(1))))) in 
  ((((linalg.iterateNumber (fun acc idx -> 
    let acc0 = (
      acc) in 
    let i = (
      idx) in 
    let mx148 = (
      linalg.iterateNumber (fun acc1 idx0 -> 
        let acc2 = (
          acc1) in 
        let k = (
          idx0) in 
        let v = (
          qs.[k]) in 
        let q = (
          qs.[k]) in 
        let l = (
          ls.[k]) in 
        let x0 = (
          x.[i]) in 
        let y = (
          means.[k]) in 
        let cur = (
          ((((alphas.[k]) + (corelang.fold (fun acc3 cur -> 
            ((acc3) + (cur))) (0.000000) (v)))) - (((0.500000) * (linalg.iterateNumber (fun acc3 idx1 -> 
            let acc4 = (
              acc3) in 
            let i0 = (
              idx1) in 
            let n0 = (
              ((i0) - (1))) in 
            let tis = (
              ((((n0) * (((n0) + (1))))) / (2))) in 
            let s = (
              Card(0)) in 
            let e = (
              corelang.length (l)) in 
            let sum = (
              linalg.iterateNumber (fun acc5 idx2 -> 
                let acc6 = (
                  acc5) in 
                let i1 = (
                  idx2) in 
                let cur = (
                  (double)(((cardToInt(s)) + (i1)))) in 
                let idx3 = (
                  (int)(cur)) in 
                let j = (
                  ((idx3) - (tis))) in 
                let isInRange = (
                  if(((j) >= (0))) then 
                    ((j) < (i0))
                  else 
                    false) in 
                if(isInRange) then 
                  let x1 = (
                    x0.[j]) in 
                  let y0 = (
                    y.[j]) in 
                  ((acc6) + (((l.[idx3]) * (((x1) - (y0))))))
                else 
                  acc6) (0.000000) (Card(0)) (((((((e) .- (s))) .+ (Card(1)))) .- (Card(1))))) in 
            let x1 = (
              x0.[i0]) in 
            let y0 = (
              y.[i0]) in 
            let x10 = (
              ((sum) + (((exp(q.[i0])) * (((x1) - (y0))))))) in 
            let cur = (
              ((x10) * (x10))) in 
            ((acc4) + (cur))) (0.000000) (Card(0)) (((corelang.length (x0)) .- (Card(1))))))))) in 
        if(((acc2) > (cur))) then 
          acc2
        else 
          cur) (-1000.000000) (Card(0)) (((K) .- (Card(1))))) in 
    let semx170172 = (
      linalg.iterateNumber (fun acc1 idx0 -> 
        let acc2 = (
          acc1) in 
        let i0 = (
          idx0) in 
        let v149 = (
          qs.[i0]) in 
        let q150 = (
          qs.[i0]) in 
        let l151 = (
          ls.[i0]) in 
        let x152 = (
          x.[i]) in 
        let y153 = (
          means.[i0]) in 
        let x168 = (
          ((((alphas.[i0]) + (corelang.fold (fun acc3 cur -> 
            ((acc3) + (cur))) (0.000000) (v149)))) - (((0.500000) * (linalg.iterateNumber (fun acc3 idx1 -> 
            let acc4 = (
              acc3) in 
            let i1 = (
              idx1) in 
            let n154 = (
              ((i1) - (1))) in 
            let tis155 = (
              ((((n154) * (((n154) + (1))))) / (2))) in 
            let s156 = (
              Card(0)) in 
            let e157 = (
              corelang.length (l151)) in 
            let sum163 = (
              linalg.iterateNumber (fun acc5 idx2 -> 
                let acc6 = (
                  acc5) in 
                let i2 = (
                  idx2) in 
                let cur = (
                  (double)(((cardToInt(s156)) + (i2)))) in 
                let idx158 = (
                  (int)(cur)) in 
                let j159 = (
                  ((idx158) - (tis155))) in 
                let isInRange160 = (
                  if(((j159) >= (0))) then 
                    ((j159) < (i1))
                  else 
                    false) in 
                if(isInRange160) then 
                  let x161 = (
                    x152.[j159]) in 
                  let y162 = (
                    y153.[j159]) in 
                  ((acc6) + (((l151.[idx158]) * (((x161) - (y162))))))
                else 
                  acc6) (0.000000) (Card(0)) (((((((e157) .- (s156))) .+ (Card(1)))) .- (Card(1))))) in 
            let x164 = (
              x152.[i1]) in 
            let y165 = (
              y153.[i1]) in 
            let x1166 = (
              ((sum163) + (((exp(q150.[i1])) * (((x164) - (y165))))))) in 
            let cur = (
              ((x1166) * (x1166))) in 
            ((acc4) + (cur))) (0.000000) (Card(0)) (((corelang.length (x152)) .- (Card(1))))))))) in 
        let cur = (
          exp(((x168) - (mx148)))) in 
        ((acc2) + (cur))) (0.000000) (Card(0)) (((K) .- (Card(1))))) in 
    let cur = (
      ((log(semx170172)) + (mx148))) in 
    ((acc0) + (cur))) (0.000000) (Card(0)) (((n) .- (Card(1))))) - ((((double)(cardToInt(n))) * (((log(semx174)) + (mx))))))) + (((0.500000) * (linalg.iterateNumber (fun acc idx -> 
    let acc0 = (
      acc) in 
    let k = (
      idx) in 
    let v = (
      qs.[k]) in 
    let x0 = (
      ls.[k]) in 
    let cur = (
      ((linalg.iterateNumber (fun acc1 idx0 -> 
        let acc2 = (
          acc1) in 
        let i = (
          idx0) in 
        let value = (
          v.[i]) in 
        let x1 = (
          exp(value)) in 
        let cur = (
          ((x1) * (x1))) in 
        ((acc2) + (cur))) (0.000000) (Card(0)) (((corelang.length (v)) .- (Card(1))))) + (linalg.iterateNumber (fun acc1 idx0 -> 
        let acc2 = (
          acc1) in 
        let i = (
          idx0) in 
        let x1 = (
          x0.[i]) in 
        let cur = (
          ((x1) * (x1))) in 
        ((acc2) + (cur))) (0.000000) (Card(0)) (((corelang.length (x0)) .- (Card(1))))))) in 
    ((acc0) + (cur))) (0.000000) (Card(0)) (((K) .- (Card(1))))))))

