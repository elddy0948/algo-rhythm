import Foundation

final class Solution2217 {
  func solve() {
    let n = Int(readLine()!)!
    var ropes = [Int]()
    
    for _ in 0 ..< n {
      let rope = Int(readLine()!)!
      ropes.append(rope)
    }
    
    let sortedRopes = ropes.sorted(by: { $0 < $1 })
    var max = -1
    
    for (index, rope) in sortedRopes.enumerated() {
      let weight = (n - index) * rope
      if max < weight { max = weight }
    }
    
    print(max)
  }
}
