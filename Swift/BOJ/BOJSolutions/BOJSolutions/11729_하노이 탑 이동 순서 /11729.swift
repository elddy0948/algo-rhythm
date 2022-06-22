import Foundation

class Solution11729 {
  func solve() {
    let readN = Int(readLine()!)!
    
    print(pow(2, readN) - 1)
    
    move(from: 1, to: 3, number: readN)
  }
  
  func move(from a: Int, to b: Int, number: Int) {
    if number == 1 {
      print("\(a) \(b)")
      return
    }
    
    move(from: a, to: 6 - a - b, number: number - 1)
    print("\(a) \(b)")
    move(from: 6 - a - b, to: b, number: number - 1)
  }
}
