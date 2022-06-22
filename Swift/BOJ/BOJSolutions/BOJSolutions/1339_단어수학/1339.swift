import Foundation

class Solution1339 {
  func solve() {
    let n: Int = Int(readLine()!)!
    var alphabetDictionary = [String: Int]()
    var alphabets = [[String]]()
    
    for _ in 0 ..< n {
      let readOneLine = readLine()!.map({
        String($0)
      })
      
      alphabets.append(readOneLine)
      
      _ = readOneLine.enumerated().map({ (index, stringChar) in
        if let _ = alphabetDictionary[stringChar] {
          let value = pow(10.0, Double(readOneLine.count - 1 - index))
          alphabetDictionary[stringChar]! += Int(value)
        } else {
          let value = pow(10.0, Double(readOneLine.count - 1 - index))
          alphabetDictionary[stringChar] = Int(value)
        }
      })
    }
      
    var number = 9
    _ = alphabetDictionary.sorted(by: { $0.value > $1.value })
      .map({ (key, value) in
        alphabetDictionary[key] = number
        number -= 1
      })
    
    var results = 0
    
    alphabets.forEach({ line in
      var number = ""
      line.forEach({ letter in
        let stringNumber = String(alphabetDictionary[letter] ?? 0 )
        number.append(stringNumber)
      })
      results += (Int(number) ?? 0)
    })
    print(results)
  }
}
