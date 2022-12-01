import Foundation

class Solution51 {
  func solveNQueens(_ n: Int) -> [[String]] {
    var ans: [[String]] = []
    var board: [[Int]] = [[Int]](repeating: [Int](repeating: 0, count: n), count: n)
    backTracking(ans: &ans, board: &board, row: 0, n: n)
    return ans
  }
  
  func backTracking(ans: inout [[String]], board: inout [[Int]], row: Int, n: Int) {
    if row == n {
      var res: [String] = []
      
      for i in 0 ..< n {
        var rowString = ""
        for j in 0 ..< n {
          if board[i][j] == 0 { rowString += "." }
          else { rowString += "Q" }
        }
        
        res.append(rowString)
      }
      ans.append(res)
    }
    
    for j in 0 ..< n {
      if check(board: board, row: row, col: j, n: n) {
        board[row][j] = 1
        backTracking(ans: &ans, board: &board, row: row + 1, n: n)
        board[row][j] = 0
      }
    }
  }
  
  private func check(board: [[Int]], row: Int, col: Int, n: Int) -> Bool {
    // Vertical
    for i in 0 ..< row {
      if board[i][col] != 0 { return false }
    }
    
    // Main diagonal
    var i = row
    var j = col
    
    while(i >= 0 && j >= 0) {
      if board[i][j] != 0 { return false }
      i -= 1
      j -= 1
    }
    
    // Secondary diagonal
    var i1 = row
    var j1 = col
    while (i1 >= 0 && j1 < n) {
      if board[i1][j1] != 0 { return false }
      i1 -= 1
      j1 += 1
    }
    
    return true
  }
}
