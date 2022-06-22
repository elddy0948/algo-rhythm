import Foundation

class Solution {
    func myPow(_ x: Double, _ n: Int) -> Double {
        if n < 0 && x != 0 {
            return myPow(1.0 / x, n * -1)
        }

        if n == 0 { return 1 }
        if n == 1 { return x }

        if n % 2 == 0 {
            let res = myPow(x, n / 2)
            return res * res
        } else {
            return myPow(x, n - 1) * x
        }
    }
}

let sol = Solution()
let result = sol.myPow(2, 10)
print(result)
