//
//  main.swift
//  1037_약수
//
//  Created by 김호준 on 2020/03/25.
//  Copyright © 2020 김호준. All rights reserved.
//

import Foundation

let read_N: Int = Int(readLine() ?? "") ?? 0
var A: [Int] = Array(repeating: 0, count: read_N)

let read_A = readLine()?.components(separatedBy: " ") ?? [""]

for i in 0..<read_A.count {
    A[i] = Int(read_A[i]) ?? 0
}
A.sort()

let answer = A[0] * A[read_N - 1]
print(answer)
