// Level 1 - x만큼 간격이 있는 n개의 숫자

import Foundation

func solution(_ x:Int, _ n:Int) -> [Int64] {
  var answer = [Int64]()
  
  answer.append(Int64(x))
  
  
  while answer.count != n {
    answer.append((answer.last ?? 0) + Int64(x))
  }
  
  return answer
}
