// Level 1 - 크레인 인형 뽑기 게임

import Foundation

func makeBoardToStack(_ board: [[Int]]) -> [[Int]] {
  var stackBoard = [[Int]]()
  for i in 0 ..< board.count {
    var stack = [Int]()
    for j in 0 ..< board.count {
      let doll = board[board.count - j - 1][i]
      if doll != 0 { stack.append(board[board.count - j - 1][i]) }
    }
    stackBoard.append(stack)
  }
  return stackBoard
}

func solution(_ board:[[Int]], _ moves:[Int]) -> Int {
  var stackBoard = makeBoardToStack(board)
  var basket = [Int]()
  var removed = 0
  
  for move in moves {
    if stackBoard[move - 1].last != nil {
      let last = stackBoard[move - 1].removeLast()
      if let tail = basket.last {
        if last == tail { basket.removeLast(); removed += 2 }
        else { basket.append(last) }
      } else {
        basket.append(last)
      }
    }
  }
  
  return removed
}
