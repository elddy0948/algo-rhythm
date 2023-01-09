import Foundation

class Solution40 {
  func combinationSum2(_ candidates: [Int], _ target: Int) -> [[Int]] {
    var combs = [[Int]]()
    var comb = [Int]()
    
    backtracking(candidates.sorted(), &combs, &comb, 0, target)
    
    return combs
  }
  
  private func backtracking(
    _ candidates: [Int],
    _ combs: inout [[Int]],
    _ comb: inout [Int],
    _ index: Int,
    _ target: Int
  ) {
    if target == 0 {
      combs.append(comb)
      return
    }
    
    for i in index ..< candidates.count {
      if candidates[i] > target { break }
      if i > 0 && candidates[i] == candidates[i - 1] && i != index { continue }
      
      comb.append(candidates[i])
      backtracking(candidates, &combs, &comb, i + 1, target - candidates[i])
      comb.removeLast()
    }
  }
}
