import Foundation


func rob(_ nums: [Int]) -> Int {
    var num1 = 0
    var num2 = 0
    
    for i in 0..<nums.count {
        if i % 2 == 0 {
            num1 = max(num1 + nums[i], num2)
        }
        if i % 2 == 1 {
            num2 = max(num2 + nums[i], num1)
        }
    }
    
    return max(num1, num2)
}

print(rob([2,7,9,3,1]))
