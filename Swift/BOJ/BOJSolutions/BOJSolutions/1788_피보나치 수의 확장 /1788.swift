import Foundation

final class Solution1788 {
  var dp = [Int](repeating: 0, count: 1000001)
  
  func negativeFib(_ target: Int) -> Int {
    for i in 2 ... target {
      dp[i] = (dp[i - 2] - dp[i - 1]) % 1_000_000_000
    }
    return dp[target]
  }
  
  func positiveFib(_ target: Int) -> Int {
    for i in 2 ... target {
      dp[i] = (dp[i - 1] + dp[i - 2]) % 1_000_000_000
    }
    return dp[target]
  }
  
  func solve() {
    let target = Int(readLine()!)!
    var answer = 0
    
    dp[0] = 0; dp[1] = 1
    
    if target == 0 {
      answer = 0
    } else if abs(target) == 1 {
      answer = 1
    } else if target < 0 {
      answer = negativeFib(abs(target))
    } else {
      answer = positiveFib(target)
    }
    
    if answer == 0 {
      print(0)
      print(answer)
    } else if answer < 0 {
      print(-1)
      print(abs(answer))
    } else {
      print(1)
      print(answer)
    }
  }
}
