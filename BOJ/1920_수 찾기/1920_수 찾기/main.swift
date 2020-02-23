//
//  main.swift
//  1920_수 찾기
//  https://www.acmicpc.net/problem/1920
//  Created by 김호준 on 2020/02/24.
//  Copyright © 2020 김호준. All rights reserved.
//

import Foundation


func solution(numberArray: [Int], numToFind: Int) -> Int {
    //Binary Search!
    
    var left: Int = 0
    var right: Int = numberArray.count - 1
    while left <= right {
        let middle = Int(floor(Double(left + right) / 2.0))
        if numberArray[middle] < numToFind {
            left = middle + 1
        } else if numberArray[middle] > numToFind {
            right = middle - 1
        } else {
            return 1
        }
    }
    
    return 0
}

let N = Int(readLine() ?? "") ?? 0

var arr: [Int] = Array<Int>(repeating: 0, count: N)

var read = readLine()?.components(separatedBy: " ")

for i in 0..<N {
    arr[i] = Int(read?[i] ?? "") ?? 0
}
arr.sort()

let M = Int(readLine() ?? "") ?? 0

read = readLine()?.components(separatedBy: " ")

for i in 0..<M {
    let answer = solution(numberArray: arr, numToFind: Int(read?[i] ?? "") ?? 0)
    print(answer)
}
