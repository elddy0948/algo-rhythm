//
//  main.swift
//  1316_그룹 단어 체커
//  https://www.acmicpc.net/problem/1316
//  Created by 김호준 on 2020/04/05.
//  Copyright © 2020 김호준. All rights reserved.
//

import Foundation


let readN = Int(readLine() ?? "") ?? 0
var counter: Int = 0


for _ in 0..<readN {
    var alphabet: [Int] = Array<Int>(repeating: 0, count: 200)
    let readString = readLine() ?? ""
    var isItGroup: Bool = true
    var beforeAlpha: Int = 0
    for al in readString {
        if alphabet[Int(al.asciiValue!)] == 0 {
            alphabet[Int(al.asciiValue!)] += 1
            beforeAlpha = Int(al.asciiValue!)
        }
        else {
            if beforeAlpha == Int(al.asciiValue!) { continue }
            else {isItGroup = false}
        }
    }
    if isItGroup { counter += 1}
}

print(counter)
