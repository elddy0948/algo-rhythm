import Foundation

func removeElement(_ nums: inout [Int], _ val: Int) -> Int {
    
    var i = 0
    var n = nums.count
    
    while i < n {
        if nums[i] == val {
            nums[i] = nums[n-1]
            n = n - 1
        } else {
            i = i + 1
        }
    }
    return n
}


//  func removeElement(_ nums: inout [Int], _ val: Int) -> Int {
//    return (nums.filter { $0 != val }).count
//  }
