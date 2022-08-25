import Foundation

class Solution9095 {
  func solve() {
    let readN = Int(readLine()!)!
    var dp = [Int](repeating: 0, count: 12)
    
    dp[1] = 1
    dp[2] = 2
    dp[3] = 4
    
    for _ in 0 ..< readN {
      let readNumber = Int(readLine()!)!
      
      if readNumber <= 3 { print(dp[readNumber]); continue }
      
      for i in 4 ... readNumber {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
      }
      
      print(dp[readNumber])
    }
  }
}
