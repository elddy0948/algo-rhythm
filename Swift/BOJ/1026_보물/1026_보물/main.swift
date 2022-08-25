//
//  main.swift
//  1026_보물
//
//  Created by 김호준 on 2020/02/27.
//  Copyright © 2020 김호준. All rights reserved.
//

import Foundation

//배열 A의 작은 값과 배열 B의 작은 값을 곱하면 그 합이 최소로 나온다.

func solution(A: [Int], B: [Int], N: Int) -> Int {
    var answer: Int = 0
    var arr_A = A
    var arr_B = B
    //A 배열 오름차순 정렬
    arr_A.sort()
    
    //B 배열 내림차순 정렬
    arr_B.sort(by: >)
    
    for i in 0..<N {
        answer += arr_A[i] * arr_B[i]
    }
    
    return answer
}

let read_N: String = readLine() ?? ""
let N: Int = Int(read_N) ?? 0

var arr_A: [Int] = Array<Int>(repeating: 0, count: N)
var arr_B: [Int] = Array<Int>(repeating: 0, count: N)

let read_A = readLine()?.components(separatedBy: " ")
let read_B = readLine()?.components(separatedBy: " ")

for i in 0..<N {
    arr_A[i] = Int(read_A?[i] ?? "") ?? 0
    arr_B[i] = Int(read_B?[i] ?? "") ?? 0
}

let ans = solution(A: arr_A, B: arr_B, N: N)
print(ans)
