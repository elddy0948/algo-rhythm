//
//  main.swift
//  2178_미로
//
//  Created by 김호준 on 2020/02/29.
//  Copyright © 2020 김호준. All rights reserved.
//

import Foundation

let read_NM = readLine()?.components(separatedBy: " ")
let N: Int = Int(read_NM?[0] ?? "") ?? 0
let M: Int = Int(read_NM?[1] ?? "") ?? 0

var arr_Path: [[String]] = Array(repeating: Array(repeating: "", count: M), count: N)

let read = readLine() ?? ""

var j: Int = 0
for i in 0..<N {
    for index in read.indices {
        arr_Path[i][j] = String(read[index])
        j += 1
    }
    j = 0
}
print(arr_Path)
