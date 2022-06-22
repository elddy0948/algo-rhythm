import Foundation

final class Joystick {
  func solution(_ name:String) -> Int {
    let stringAlphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    var alphabetDict = [String: Int]()
    stringAlphabets.enumerated().forEach({ alphabetDict[String($1)] = $0 })
    let nameArray = name.map({ String($0) })
    var answer = 0
    var minimumMove = nameArray.count - 1
    

    for alphabet in nameArray {
      if alphabet != "A" {
        let z = alphabetDict["Z"] ?? 25
        let a = alphabetDict["A"] ?? 0
        let alphabetIndex = alphabetDict[String(alphabet)] ?? 0
        answer += min(z - alphabetIndex + 1, alphabetIndex - a)
      }
    }
    
    
    for i in 0 ..< nameArray.count {
      var next = i + 1
      while next < nameArray.count && nameArray[next] == "A" {
        next += 1
      }
      let leftOrRight = min(i + (i + nameArray.count - next), 2 * (nameArray.count - next) + i)
      minimumMove = min(minimumMove, leftOrRight)
    }
    
    answer += minimumMove
    
    return answer
  }
}
