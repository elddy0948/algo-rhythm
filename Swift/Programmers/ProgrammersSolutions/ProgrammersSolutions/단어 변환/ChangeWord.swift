import Foundation

class ChangeWord {
  var wordsArray: [String] = []
  var answer = 50
  var visited = [Bool](repeating: false, count: 51)
  
  func checkDifference(_ lhs: String, rhs: String) -> Bool {
    var differenceCount = 0
    let lhsArray = Array(lhs)
    let rhsArray = Array(rhs)
    
    for i in 0 ..< rhsArray.count {
      if lhsArray[i] != rhsArray[i] {
        differenceCount += 1
      }
      if differenceCount > 1 { return false }
    }
    if differenceCount == 1 { return true }
    return false
  }

  func dfs(begin: String, target: String, level: Int) {
    if answer <= level { return }
    if begin == target {
      answer = min(answer, level)
      return
    }
    
    for i in 0 ..< wordsArray.count {
      //다른 것이 하나이고, 방문하지 않았을 때
      if checkDifference(begin, rhs: wordsArray[i]) && !visited[i] {
        visited[i] = true
        dfs(begin: wordsArray[i], target: target, level: level + 1)
        visited[i] = false
      }
    }
    return
  }

  func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    wordsArray = words
    dfs(begin: begin, target: target, level: 0)
    if answer == 50 { return 0 }
    return answer
  }
}
