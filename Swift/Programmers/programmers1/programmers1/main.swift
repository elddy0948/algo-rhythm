//
//  main.swift
//  programmers1
//
//  Created by 김호준 on 2020/04/10.
//  Copyright © 2020 김호준. All rights reserved.
//

import Foundation

func solution(_ n: Int) -> Int {
//    1-1. 입력된 수가 짝수라면 2로 나눕니다.
//    1-2. 입력된 수가 홀수라면 3을 곱하고 1을 더합니다.
//    2. 결과로 나온 수에 같은 작업을 1이 될 때까지 반복합니다.
    var number = n
    var cnt: Int = 0
    while number != 1 {
        if cnt > 500 {
            cnt = -1
            break;
        }
        if number % 2 == 0 {
            number /= 2
            cnt += 1
        } else if number % 2 == 1 {
            number = (number * 3) + 1
            cnt += 1
        }
    }
    return cnt
}
let read = Int((readLine())!)!
let answer = solution(read)
print(answer)
