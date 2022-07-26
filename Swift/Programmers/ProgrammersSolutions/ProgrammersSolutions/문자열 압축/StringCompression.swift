import Foundation

final class StringCompression {
  func solution(_ s:String) -> Int {
    if s.count <= 2 { return s.count }
    
    var result: Int = 0
    
    for windowSize in 1 ... (s.count / 2) {
      let slicingStrings = slicingString(s, windowSize: windowSize)
      let compressedString = compress(slicingStrings)
      
      result = (result > 0) ? min(result, compressedString.count) : compressedString.count
    }
    return result
  }
  
  func slicingString(_ str: String, windowSize: Int) -> [String] {
    let strings = Array(str)
    let length = strings.count
    var words = [String]()
    
    for i in stride(from: windowSize - 1, to: length, by: windowSize) {
      let word = strings[(i - windowSize + 1) ... i].map({ String($0) }).joined()
      words.append(word)
    }
    
    if length % windowSize > 0 {
      words.append(String(strings[(length - (length % windowSize))...]))
    }
    return words
  }
  
  func compress(_ strings: [String]) -> String {
    let length = strings.count
    var count = 1
    var string = ""
    
    for i in 0 ..< (length - 1) {
      if strings[i] == strings[i + 1] { count += 1}
      else {
        let addString = (count > 1) ? ("\(count)\(strings[i])") : ("\(strings[i])")
        string += addString
        count = 1
      }
    }
    let addString = (count > 1) ? ("\(count)\(strings[length - 1])") : ("\(strings[length - 1])")
    string += addString
    return string
  }
}
