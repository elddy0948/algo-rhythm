import Foundation

func findContentChildren(_ g: [Int], _ s: [Int]) -> Int {
  
  var answer = 0
  
  let sortedG = g.sorted()
  let sortedS = s.sorted()
  
  var childPointer = 0
  var cookiePointer = 0
  
  while childPointer < sortedG.count && cookiePointer < sortedS.count {
    if sortedS[cookiePointer] >= sortedG[childPointer] {
      answer += 1
      childPointer += 1
      cookiePointer += 1
    } else {
      cookiePointer += 1
    }
  }
  
  return answer
}


print(findContentChildren([1, 2], [1, 2, 3]))
