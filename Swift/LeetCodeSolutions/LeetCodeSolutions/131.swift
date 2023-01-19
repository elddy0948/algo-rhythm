import Foundation

class Solution131 {
  func partition(_ s: String) -> [[String]] {
    var answers = [[String]]()
    var partition = [String]()
    
    
    backtracking(&answers, &partition, Array(s), 0)
    
    return answers
  }
  
  private func backtracking(_ answers: inout [[String]],
                            _ partition: inout [String],
                            _ s: [Character],
                            _ index: Int) {
    if index == s.count {
      answers.append(partition)
      return
    }
    
    for i in index ..< s.count {
      let substring = String(s[index...i])
      if checkIsPalindrome(substring) {
        partition.append(substring)
        backtracking(&answers, &partition, s, i + 1)
        partition.removeLast()
      }
    }
  }
  
  private func checkIsPalindrome(_ string: String) -> Bool {
    let arr = Array(string)
    var start = 0
    var end = arr.count - 1
    
    while start <= end {
      if arr[start] != arr[end] { return false }
      start += 1
      end -= 1
    }
    
    return true
  }
}
