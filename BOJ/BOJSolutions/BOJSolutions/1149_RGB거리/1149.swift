import Foundation

final class Solution1149 {
  func solve() {
    let n = Int(readLine()!)!
    var houses = [[Int]](repeating: [Int](repeating: 0, count: 3), count: 1001)
    
    houses[0][0] = 0; houses[0][1] = 0; houses[0][2] = 0
    
    for i in 1 ... n {
      let costs = readLine()!.split(separator: " ").map({ Int($0)! })
      houses[i][0] = min(houses[i - 1][1], houses[i - 1][2]) + costs[0]
      houses[i][1] = min(houses[i - 1][0], houses[i - 1][2]) + costs[1]
      houses[i][2] = min(houses[i - 1][0], houses[i - 1][1]) + costs[2]
    }
    
    print(min(houses[n][0], min(houses[n][1], houses[n][2])))
  }
}
