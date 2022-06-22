import Foundation

final class MatrixMultiplication {
  func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    var answer = [[Int]](repeating: [Int](repeating: 0, count: arr2[0].count), count: arr1.count)
    
    for i in 0 ..< answer.count {
      for j in 0 ..< answer[i].count {
        for k in 0 ..< arr2.count {
          answer[i][j] += (arr1[i][k] * arr2[k][j])
        }
      }
    }
    
    return answer
  }
}
