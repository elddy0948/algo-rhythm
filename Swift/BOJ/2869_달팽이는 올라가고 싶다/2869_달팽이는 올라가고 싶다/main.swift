//
//  main.swift
//  2869_달팽이는 올라가고 싶다
//  https://www.acmicpc.net/problem/2869
//  Created by 김호준 on 2020/02/27.
//  Copyright © 2020 김호준. All rights reserved.
//

import Foundation

func solution(up: Int, down: Int, height: Int) -> Int {
    var answer: Int = 0
    answer = (height - down - 1) / (up - down) + 1
    return answer
}

let read: [String] = readLine()?.components(separatedBy: " ") ?? [""]
let goUp: Int = Int(read[0]) ?? 0
let goDown: Int = Int(read[1]) ?? 0
let height: Int = Int(read[2]) ?? 0

let ans = solution(up: goUp, down: goDown, height: height)

print(ans)
