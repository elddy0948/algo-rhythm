import Foundation

class Solution17 {
  private let numberToString = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
  
  func letterCombinations(_ digits: String) -> [String] {
    var combs = [String]()
    var comb = ""
    
    backtracking(&combs, &comb, digits, 0)
    
    return combs
  }
  
  private func backtracking(_ combs: inout [String], _ comb: inout String, _ digits: String, _ index: Int) {
    if comb.count == digits.count {
      if comb == "" { return }
      combs.append(comb)
      return
    }
    
    let currentIndexString = getAvailableString(from: digits, at: index, numberToString)
    
    for character in currentIndexString {
      comb.append(character)
      backtracking(&combs, &comb, digits, index + 1)
      comb.removeLast()
    }
  }
  
  private func getAvailableString(from digits: String, at index: Int, _ numberToString: [String]) -> String {
    guard index >= 0, index < digits.count else { return "" }
    let currentDigit = digits[digits.index(digits.startIndex, offsetBy: index)]
    guard let currentIndex = Int(String(currentDigit)) else { return "" }
    return numberToString[currentIndex]
  }
}
