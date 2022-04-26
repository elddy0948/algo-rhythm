import Foundation

final class Solution15650 {
  var n: Int = 0
  var m: Int = 0
  var arr: [Int] = Array<Int>(repeating: 0, count: 9)
  var visited: [Bool] = Array<Bool>(repeating: false, count: 9)
  
  func recursion(k: Int, number: Int) {
    if k == m {
      //수열 완성
      for i in 0 ..< m {
        print("\(arr[i]) ", terminator: "")
      }
      print("")
      return
    }
    
    for i in number ... n {
      if !visited[i] {
        //방문하지 않았다면
        arr[k] = i
        visited[i] = true
        recursion(k: k + 1, number: i)
        visited[i] = false
      }
    }
  }
  
  func solve() {
    let readNM = readLine()!.components(separatedBy: " ").map({ Int($0)! })
    n = readNM[0]
    m = readNM[1]
    
    recursion(k: 0, number: 1)
  }
}
