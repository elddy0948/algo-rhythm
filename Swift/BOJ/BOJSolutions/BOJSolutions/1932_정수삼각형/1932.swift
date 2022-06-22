//
//  1932.swift
//  BOJSolutions
//
//  Created by 김호준 on 2022/05/24.
//

import Foundation

final class Solution1932 {
  func solve() {
    //arr[i][j] = arr[i + 1][j] + arr[i + 1][j + 1]
    
    let n = Int(readLine()!)!
    var arr = [[Int]](repeating: [Int](repeating: 0, count: 501), count: 501)
    var sumArray = [[Int]](repeating: [Int](repeating: 0, count: 501), count: 501)
    
    for i in 0 ..< n {
      let line = readLine()!.split(separator: " ").map({ Int(String($0))! })
      for (index, value) in line.enumerated() {
        arr[i][index] = value
      }
    }
    
    sumArray[0][0] = arr[0][0]
    
    for i in 1 ..< n {
      for j in 0 ..< i + 1 {
        if j == 0 {
          sumArray[i][j] = sumArray[i - 1][j] + arr[i][j]
        } else if j == i {
          sumArray[i][j] = sumArray[i - 1][j - 1] + arr[i][j]
        } else {
          sumArray[i][j] = max(sumArray[i - 1][j - 1], sumArray[i - 1][j]) + arr[i][j]
        }
      }
    }
    
    print(sumArray[n - 1].max() ?? 0)
  }
}
