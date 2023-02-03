import Foundation

class Solution746 {
  func minCostClimbingStairs(_ cost: [Int]) -> Int {
    var dp = [Int](repeating: Int.max, count: cost.count + 1)
    let costSize = cost.count
    
    dp[0] = cost[0]
    dp[1] = cost[1]
    
    for i in 2 ... costSize {
      if i == costSize {
        dp[i] = min(dp[i - 1], dp[i - 2])
      } else {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]
      }
    }
    
    return dp[costSize]
  }
}
