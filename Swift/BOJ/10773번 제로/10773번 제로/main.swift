//
//  main.swift
//  10773번 제로
//
//  Created by 김호준 on 2020/11/07.
//

import Foundation

let K = Int(readLine()!)!
var numberStack = [Int]()
var answer = 0

for _ in 0..<K {
    let number = Int(readLine()!)!
    if number == 0 {
        let _ = numberStack.popLast()
    } else {
        numberStack.append(number)
    }
}

for number in numberStack {
    answer += number
}
print(answer)

