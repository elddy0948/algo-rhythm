//
//  main.swift
//  3448_문자 인식
//  https://www.acmicpc.net/problem/3448
//  Created by 김호준 on 2020/04/05.
//  Copyright © 2020 김호준. All rights reserved.
//

import Foundation

let read_N = Int(readLine() ?? "") ?? 0

for _ in 0..<read_N {
//    print(read_N)
    var stringArr: [String] = [""]
    var R: Int = 0
    var A: Int = 0
    while true {
        let input = readLine() ?? ""
//        print(input)
        if input == "" {
//            print("input end!")
            break
        } else {
            stringArr.append(input)
        }
    }
    for i in 0..<stringArr.count {
        A += stringArr[i].count
        for ch in stringArr[i] {
            if ch != "#" {
                R += 1
            }
        }
    }
    let total_num: Double = (Double(R) / Double(A)) * 100.0
    let roundedNum = round(total_num * 10) / 10
    let intNum = Int(roundedNum) * 10
    let otherNum = Int(roundedNum * 10.0)
    if intNum == otherNum {
        print("Efficiency ratio is \(Int(roundedNum))%.")
    } else {
        print("Efficiency ratio is \(roundedNum)%.")
    }
}
//Pr#nt ex##tly one##ine for#eac# te#t c#se.

