import Foundation

class Solution1463 {
  func solve() {
    let n = Int(readLine()!)!
    var arr = [Int](repeating: 0, count: n + 1)
    
    if n == 1 {
      print(arr[1])
    } else {
      for i in 2 ... n {
        arr[i] = arr[i - 1] + 1
        if i % 2 == 0 {
          //2로 나누어 떨어짐
          arr[i] = min(arr[i], arr[i / 2] + 1)
        }
        if i % 3 == 0 {
          //3으로 나누어 떨어짐
          arr[i] = min(arr[i], arr[i / 3] + 1)
        }
      }
      
      print(arr[n])
    }
  }
}
