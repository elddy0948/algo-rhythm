import Foundation

final class Solution1254 {
  var string = [String]()
  
  func isPalindrome(index: Int) -> Bool {
    var startIndex = index
    var endIndex = string.count - 1
    
    while startIndex < endIndex {
      if string[startIndex] != string[endIndex] {
        return false
      }
      startIndex += 1
      endIndex -= 1
    }
    return true
  }
  
  func solve() {
    let readString = readLine()!.map({ String($0) })
    string = readString
    var startIndex = 0
    
    while !isPalindrome(index: startIndex) {
      startIndex += 1
    }
    
    print(readString.count + startIndex)
  }
}
