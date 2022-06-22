//
//  main.swift
//  1337_올바른 배열
//
//  Created by 김호준 on 2020/03/24.
//  Copyright © 2020 김호준. All rights reserved.
//

import Foundation


let read_N = Int(readLine() ?? "") ?? 0
var arr: [Int] = Array<Int>(repeating: 9987654321, count: 10001)
var arr_index = 0
var cnt = 1
var answer = 1

for i in 0..<read_N {
    arr[i] = Int(readLine() ?? "") ?? 0
}
arr.sort()

for i in 1..<read_N {
    cnt += 1
    while arr[i] - arr[arr_index] > 4 {
        cnt -= 1
        arr_index += 1
    }
    answer = max(answer, cnt)
}
if answer > 5 {
    answer = 5
}
print(5 - answer)
