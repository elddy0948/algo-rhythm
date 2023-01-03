import Foundation

class Solution90 {
  private var answer = Set<[Int]>()
  
  func backtrack(_ subsets: inout [Int], _ nums: [Int], _ index: Int) {
    if index == nums.count {
      answer.insert(subsets)
      return
    }
    
    backtrack(&subsets, nums, index + 1)
    subsets.append(nums[index])
    backtrack(&subsets, nums, index + 1)
    subsets.removeLast()
  }
  
  func subsetsWithDup(_ nums: [Int]) -> [[Int]] {
    var subsets = [Int]()
    let sortedNums = nums.sorted()
    backtrack(&subsets, sortedNums, 0)
    return Array(answer)
  }
}
