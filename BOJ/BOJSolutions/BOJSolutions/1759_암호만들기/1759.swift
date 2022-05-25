//
//  1759.swift
//  BOJSolutions
//
//  Created by 김호준 on 2022/05/26.
//

import Foundation


final class Solution1759 {
  
  let vowels = ["a", "e", "i", "o", "u"]
  var possibleWords = [String]()
  var l = 0
  
  func searchPassword(startIndex: Int, password: String, consonantCount: Int, vowelCount: Int) {
    if password.count == l {
      if consonantCount >= 2 && vowelCount >= 1 {
        print(password)
      }
      return
    }
    
    for index in startIndex ..< possibleWords.count {
      if vowels.contains(possibleWords[index]) {
        searchPassword(
          startIndex: index + 1,
          password: password + possibleWords[index],
          consonantCount: consonantCount,
          vowelCount: vowelCount + 1
        )
      } else {
        searchPassword(
          startIndex: index + 1,
          password: password + possibleWords[index],
          consonantCount: consonantCount + 1,
          vowelCount: vowelCount
        )
      }
    }
  }
  
  func solve() {
    let readLC = readLine()!.split(separator: " ").map({ Int($0)! })
    l = readLC[0]
    
    let readPossibleWords = readLine()!.split(separator: " ").map({ String($0) })
    
    possibleWords = readPossibleWords.sorted()
    
    searchPassword(startIndex: 0, password: "", consonantCount: 0, vowelCount: 0)
  }
}
