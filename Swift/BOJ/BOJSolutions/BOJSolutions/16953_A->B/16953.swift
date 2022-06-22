import Foundation

final class Solution16953 {
  func solve() {
    let readAandB: [Int] = readLine()!.split(separator: " ").map({ Int($0)! })
    let a: Int = readAandB[0]
    let b: Int = readAandB[1]
    
    var queue: [(Int, Int)] = []
    var canMakelevel: Int = -1
    
    queue.append((a, 1))
    
    while !queue.isEmpty {
      let numberAndLevel: (Int, Int) = queue.removeFirst()
      let level = numberAndLevel.1 + 1
      
      let doubleA = numberAndLevel.0 * 2
      if doubleA > b { continue }
      else if doubleA == b { canMakelevel = level; break }
      else { queue.append((doubleA, level)) }
      
      let addOne = numberAndLevel.0 * 10 + 1
      if addOne > b { continue }
      else if addOne == b { canMakelevel = level; break }
      else { queue.append((addOne, level)) }
    }
    
    print(canMakelevel)
  }
}
