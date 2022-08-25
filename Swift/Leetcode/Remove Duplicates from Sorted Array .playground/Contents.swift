import Foundation

func removeDuplicates(_ nums: inout [Int]) -> Int {
    if nums.count == 0 {
        return 0
    }
    var i = 0
    for j in 0...nums.count-1{
        if nums[i] != nums[j]{
            i += 1
            nums[i] = nums[j]
        }
    }
    return i+1
}
