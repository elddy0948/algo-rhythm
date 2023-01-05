import Foundation

class Solution77 {
  private var combs = [[Int]]()
  
  private func backtracking(_ comb: inout [Int], _ k: Int, _ n: Int, _ number: Int) {
    if comb.count == k {
      combs.append(comb)
      return
    }
    
    for i in number ..< n {
      comb.append(i + 1)
      backtracking(&comb, k, n, i + 1)
      comb.removeLast()
    }
  }
  
  func combine(_ n: Int, _ k: Int) -> [[Int]] {
    var comb = [Int]()
    backtracking(&comb, k, n, 0)
    
    return combs
  }
}
