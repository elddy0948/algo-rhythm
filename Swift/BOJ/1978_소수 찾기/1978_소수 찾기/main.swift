//
//  main.swift
//  1978_소수 찾기
//
//  Created by 김호준 on 2020/02/28.
//  Copyright © 2020 김호준. All rights reserved.
//

import Foundation

//소수는 1과 그 수 자신 이외의 자연수로는 나눌 수 없는 자연수.
func solution(number: Int) -> Int {
    if number == 1 {
        return 0
    }else if number == 2 {
        return 1
    }
    //2 이상 자신 미만의 수 중에 나누어 떨어지는 게 있으면 소수가 아니다
    for i in 2..<number {
        if number % i == 0 {
            return 0
        }
    }
    return 1
}


let N: Int = Int(readLine() ?? "") ?? 0
let read_Numbers = readLine()?.components(separatedBy: " ") ?? [""]

var ans: Int = 0

for i in 0..<N {
    ans += solution(number: Int(read_Numbers[i]) ?? 0)
}
print(ans)
