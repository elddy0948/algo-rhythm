//
//  MakeBigNumber.swift
//  ProgrammersSolutions
//
//  Created by 김호준 on 2022/05/23.
//

import Foundation

final class MakeBigNumber {
  func solution(_ number:String, _ k:Int) -> String {
    var answer = ""
    let numberArray = number.map({ Int(String($0))! })
    
    var largestNumberPosition = -1
    
    for i in 0 ..< numberArray.count - k {
      var largestNumber = -1
      for j in largestNumberPosition + 1 ... k + i {
        if largestNumber < numberArray[j] {
          largestNumberPosition = j
          largestNumber = numberArray[j]
        }
      }
      answer += String(largestNumber)
    }
    
    return answer
  }
}
