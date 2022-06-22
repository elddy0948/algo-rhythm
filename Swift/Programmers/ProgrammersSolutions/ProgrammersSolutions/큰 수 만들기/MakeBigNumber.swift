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
    
    if numberArray.count - k == 1 { return String(numberArray.max() ?? 0) }
    
    for i in 0 ..< numberArray.count - k {
      var largestNumber = -1
      for j in largestNumberPosition + 1 ... k + i {
        if numberArray[j] == 9 {
          largestNumberPosition = j
          largestNumber = numberArray[j]
          break
        }
        
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
