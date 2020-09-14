import Foundation


func max(a: Int, b: Int) -> Int {
    return a > b ? a : b
}

func maxSubArray(_ nums: [Int]) -> Int {
    
    var max_end = nums[0]
    var max_far = nums[0]
    
    for i in 1..<nums.count {
        max_end = max(nums[i], max_end + nums[i])
        max_far = max(max_far,max_end)
    }
    return max_far
    
}

print(maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
