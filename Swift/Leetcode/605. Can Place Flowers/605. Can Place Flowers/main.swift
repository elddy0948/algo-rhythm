//
//  main.swift
//  605. Can Place Flowers
//
//  Created by 김호준 on 2021/12/22.
//

import Foundation

class Solution {
  func canPlaceFlowers(_ flowerbed: [Int], _ n: Int) -> Bool {
    var answer = false
    var remainFlowers = n
    var flowerBed = flowerbed
    
    if n == 0 { return true }
    
    if flowerBed.count == 1 {
      if flowerBed[0] == 1 { return false }
      else { return true }
    }
    
    for (index, bed) in flowerbed.enumerated() {
      if bed == 0 {
        if index - 1 < 0 {
          if flowerBed[index + 1] == 0 {
            remainFlowers -= 1
            flowerBed[index] = 1
            continue
          }
        } else if index + 1 == flowerBed.count {
          if flowerBed[index - 1] == 0 {
            remainFlowers -= 1
            flowerBed[index] = 1
            continue
          }
        } else {
          if flowerBed[index - 1] == 0 && flowerBed[index + 1] == 0 {
            remainFlowers -= 1
            flowerBed[index] = 1
            continue
          }
        }
      }
    }
    
    answer = (remainFlowers <= 0) ? true : false
    return answer
    
  }
}

let solution = Solution()
let result = solution.canPlaceFlowers([0], 1)
print(result)
