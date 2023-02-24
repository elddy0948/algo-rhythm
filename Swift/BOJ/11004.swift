//
//  main.swift
//  11004_K번째 수
//
//  Created by 김호준 on 2020/03/26.
//  Copyright © 2020 김호준. All rights reserved.
//

import Foundation

let read = readLine()?.components(separatedBy: " ")
let read_N = Int(read?[0] ?? "") ?? 0
let read_K = Int(read?[1] ?? "") ?? 0
var arr: [Int] =  Array<Int>(repeating: 0, count: read_N)

let read_Numbers = readLine()?.components(separatedBy: " ")

for i in 0..<read_N {
    arr[i] = Int(read_Numbers?[i] ?? "") ?? 0
}
arr.sort()

print(arr[read_K - 1])
