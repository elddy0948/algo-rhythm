import Foundation

class Solution1541 {
  func solve() {
    let readFomula = readLine()!
    
    let splitAfterMinus = readFomula.split(separator: "-")
    
    let lhs = splitAfterMinus[0].split(separator: "+").reduce(0, { (result, string) -> Int in
      return result + (Int(string) ?? 0)
    })
    
    var rhs = 0
    
    for i in 1 ..< splitAfterMinus.count {
      let totalValue = splitAfterMinus[i].split(separator: "+").reduce(0, { (result, string) -> Int in
        return result + (Int(string) ?? 0)
      })
      
      rhs -= totalValue
    }
    
    print(lhs + rhs)
  }
}
