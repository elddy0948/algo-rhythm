import Foundation

class Solution1439 {
  func solve() {
    let readString = readLine()!.map({ String($0) })
    
    var zeroCount = 0
    var oneCount = 0
    
    for (index, number) in readString.enumerated() {
      
      if index != 0 {
        if readString[index - 1] == number {
          continue
        }
      }
      
      if number == "0" {
        zeroCount += 1
      } else {
        oneCount += 1
      }
    }
    
    print(min(zeroCount, oneCount))
  }
}
