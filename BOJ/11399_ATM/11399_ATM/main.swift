//
//  main.swift
//  11399_ATM
//
//  Created by 김호준 on 2020/02/29.
//  Copyright © 2020 김호준. All rights reserved.
//

import Foundation

//매우 쉬운 그리디 알고리즘 입니다.
//작은 시간 순서대로 줄을 서서 현금을 인출하면 최소 시간이 됩니다.

let read_N: Int = Int(readLine() ?? "") ?? 0
let read_numbers = readLine()?.components(separatedBy: " ")
var numbers: [Int] = Array<Int>(repeating: 0, count: read_N)
for i in 0..<read_N {
    numbers[i] = Int(read_numbers?[i] ?? "") ?? 0
}

//정렬을 사용하여 낮은 숫자가 제일 앞에오도록 합니다.
numbers.sort()

var answer: Int = 0

for i in 0..<numbers.count {
    for j in 0...i {
        answer += numbers[j]
    }
}

print(answer)
