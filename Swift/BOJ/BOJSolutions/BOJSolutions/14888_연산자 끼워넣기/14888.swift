import Foundation

class Solution14888 {
  var operands = [Int]()
  var operators = [Int]()
  var n = 0
  var maxValue = Int.min
  var minValue = Int.max
  
  func recursion(value: Int, index: Int) {
    if index == n {
      if value > maxValue { maxValue = value }
      if value < minValue { minValue = value }
      return
    }
    
    for i in 0 ..< 4 {
      if operators[i] > 0 {
        switch i {
        case 0:
          operators[i] -= 1
          recursion(value: value + operands[index], index: index + 1)
        case 1:
          operators[i] -= 1
          recursion(value: value - operands[index], index: index + 1)
        case 2:
          operators[i] -= 1
          recursion(value: value * operands[index], index: index + 1)
        case 3:
          operators[i] -= 1
          recursion(value: value / operands[index], index: index + 1)
        default:
          break
        }
        operators[i] += 1
      }
    }
    return
  }
  
  func solve() {
    n = Int(readLine()!)!
    
    let readOperands = readLine()!.split(separator: " ").map({ Int(String($0))! })
    operands = readOperands
    
    let readOperators = readLine()!.split(separator: " ").map({ Int(String($0))! })
    operators = readOperators
    
    recursion(value: operands[0], index: 1)
    
    print(maxValue)
    print(minValue)
  }
}
