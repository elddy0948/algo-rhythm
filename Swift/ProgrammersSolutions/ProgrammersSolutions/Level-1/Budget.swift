// Level 1 - 예산

import Foundation

func solution(_ d:[Int], _ budget:Int) -> Int {
  let sortedBudgets = d.sorted()
  
  var total = 0
  var answer = 0
  
  for cost in sortedBudgets {
    if total + cost > budget { break }
    total += cost
    answer += 1
  }
  
  return answer
}
