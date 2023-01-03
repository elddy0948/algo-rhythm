import Foundation

class Solution78 {
  private var answer = [[Int]]()
  
  func backtrack(_ subsets: inout [Int], nums: [Int], index: Int) {
    if index == nums.count {
      answer.append(subsets)
      return
    }
    
    backtrack(&subsets, nums: nums, index: index + 1)
    subsets.append(nums[index])
    backtrack(&subsets, nums: nums, index: index + 1)
    subsets.removeLast()
  }
  
  func subsets(_ nums: [Int]) -> [[Int]] {
    var subsets = [Int]()
    backtrack(&subsets, nums: nums, index: 0)
    return answer
  }
}
