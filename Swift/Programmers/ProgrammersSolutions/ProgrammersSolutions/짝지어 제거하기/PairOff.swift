import Foundation

final class PairOff {
  func solution(_ s:String) -> Int{
    var answer:Int = -1
    var stackArray = [String]()
    
    if s.count % 2 == 1 { return 0 }
    
    s.forEach({ letter in
      let stringLetter = String(letter)
      if stackArray.isEmpty { stackArray.append(stringLetter) }
      else {
        if (stackArray.last ?? "") == stringLetter {
          _ = stackArray.popLast()
        } else {
          stackArray.append(stringLetter)
        }
      }
    })
    
    stackArray.isEmpty ? (answer = 1) : (answer = 0)
    
    return answer
  }
}
