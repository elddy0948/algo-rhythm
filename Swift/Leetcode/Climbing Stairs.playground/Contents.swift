import Foundation


// DP
func climbStairs(_ n: Int) -> Int {
    var dp: [Int] = [0, 1, 2]
    if n > 2 {
        for i in 3...n {
            dp.append(dp[i - 1] + dp[i - 2])
        }
    }
    return dp[n]
}

print(climbStairs(10))

