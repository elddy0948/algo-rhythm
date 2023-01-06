import Foundation

class Solution46 {
  private func backtracking(
    _ nums: [Int],
    _ results: inout [[Int]],
    _ combs: inout [Int],
    _ visited: inout [Bool]
  ) {
    if combs.count == nums.count {
      results.append(combs)
      return
    }
    
    for (index, num) in nums.enumerated() {
      if !visited[index] {
        combs.append(num)
        visited[index] = true
        backtracking(nums, &results, &combs, &visited)
        visited[index] = false
        combs.removeLast()
      }
    }
  }
  
  func permute(_ nums: [Int]) -> [[Int]] {
    var results = [[Int]]()
    var combs = [Int]()
    var visited = [Bool](repeating: false, count: nums.count)
    
    backtracking(nums, &results, &combs, &visited)
    
    return results
  }
}
