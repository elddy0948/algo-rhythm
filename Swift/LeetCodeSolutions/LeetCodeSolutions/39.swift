import Foundation

class Solution39 {
  func BackTracking(
    _ candidates: [Int],
    _ target: Int,
    _ index: Int,
    _ combinations: inout [[Int]],
    _ combination: inout [Int]) {
      
      if target == 0 {
        combinations.append(combination)
        return
      }
      
      for i in index ..< candidates.count {
        guard candidates[i] <= target else { break }
        combination.append(candidates[i])
        BackTracking(candidates, target - candidates[i], i, &combinations, &combination)
        combination.removeLast()
      }
    }
  
  func combinationSum(_ candidates: [Int], _ target: Int) -> [[Int]] {
    var combinations = [[Int]]()
    var combination = [Int]()
    
    BackTracking(candidates.sorted(), target, 0, &combinations, &combination)

    return combinations
  }
}
