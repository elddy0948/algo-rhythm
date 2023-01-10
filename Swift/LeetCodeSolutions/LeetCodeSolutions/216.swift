import Foundation

class Solution216 {
  func combinationSum3(_ k: Int, _ n: Int) -> [[Int]] {
    var combs = [[Int]]()
    var comb = [Int]()
    
    backtracking(&combs, &comb, n, k, 1)
    
    return combs
  }
  
  private func backtracking(
    _ combs: inout [[Int]],
    _ comb: inout [Int],
    _ target: Int,
    _ n: Int,
    _ nextNumber: Int
  ) {
    if comb.count == n {
      if target == 0 {
        combs.append(comb)
        return
      } else { return }
    }
    
    if target < 0 || nextNumber > 9 { return }
    
    for number in nextNumber ... 9 {
      comb.append(number)
      backtracking(&combs, &comb, target - number, n, number + 1)
      comb.removeLast()
    }
  }
}
