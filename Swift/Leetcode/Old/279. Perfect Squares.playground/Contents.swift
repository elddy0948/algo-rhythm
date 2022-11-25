//279. Perfect Squares
import Foundation


class Solution {
    private var dp: [Int]!
    
    func numSquares(_ n: Int) -> Int {
        dp = [Int](repeating: Int.max, count: n + 1)
        dp[0] = 0
        
        for i in 0..<dp.count {
            var j = 1
            while j * j <= i {
                dp[i] = min(dp[i], dp[i - j * j] + 1)
                j += 1
            }
        }

        return dp.last!
    }
}


let solution = Solution()
print(solution.numSquares(12))
