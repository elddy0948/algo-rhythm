// Level 1 - [1차] 다트 게임

import Foundation

func solution(_ dartResult:String) -> Int {
  var reversedDartResult = dartResult.reversed().map({ String($0) })
  var tryArray = [Int]()
  
  for i in 0 ..< 3 {
    var stringPoint = ""
    
    while true {
      guard let top = reversedDartResult.last else { break }
      
      if isBonus(top) {
        let point = Int(stringPoint) ?? 1
        let bonusPoint = calculateBonus(top)
        let totalPoint = Int(pow(Double(point), Double(bonusPoint)))
        tryArray.append(totalPoint)
      } else if isOption(top) {
        if top == "*" {
          if i == 0 { tryArray[i] *= 2 }
          else {
            tryArray[i - 1] *= 2
            tryArray[i] *= 2
          }
        } else {
          tryArray[i] *= -1
        }
      } else {
        if (tryArray.count - 1) == i { break }
        stringPoint.append(top)
      }
      
      reversedDartResult.removeLast()
    }
  }
  
  return tryArray[0] + tryArray[1] + tryArray[2]
}

func calculateBonus(_ bonus: String) -> Int {
  if bonus == "S" { return 1 }
  else if bonus == "D" { return 2 }
  else { return 3 }
}

func isBonus(_ c: String) -> Bool {
  return c == "S" || c == "D" || c == "T"
}

func isOption(_ c: String) -> Bool {
  return c == "*" || c == "#"
}
