//
//  main.swift
//  1654_랜선 자르기
//
//  Created by 김호준 on 2020/03/26.
//  Copyright © 2020 김호준. All rights reserved.
//

import Foundation

var highValue = 0
var lowValue = 1

let read = readLine()?.components(separatedBy: " ")
let read_K: Int = Int(read?[0] ?? "") ?? 0
let read_N: Int = Int(read?[1] ?? "") ?? 0
var arr: [Int] = Array<Int>(repeating: 0, count: read_K)
var result: Int = 0

//middle 값으로 개수 만큼 만들 수 있는지 조사.
func possible(middle: Int) -> Bool {
    var cnt = 0
    for i in 0..<read_K {
        cnt += (arr[i] / middle)
    }
    if cnt >= read_N {
        return true
    }
    return false
}

for i in 0..<read_K {
    let readNum = Int(readLine() ?? "") ?? 0
    arr[i] = readNum
    highValue = max(highValue, readNum)
}

//이분탐색
while lowValue <= highValue {
    let mid = (lowValue + highValue) / 2
    if possible(middle: mid) {
        if result < mid {
            result = mid
        }
        lowValue = mid + 1
    } else {
        highValue = mid - 1
    }
}
print(result)

