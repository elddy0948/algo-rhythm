import Foundation

typealias Board = [[Character]]

class Solution {
    private let markO = Character("O")
    private let markX = Character("X")
    private let markStar = Character("*")
    private let directions: [(Int, Int)] = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    private var boardWidth = 0
    private var boardHeight = 0
    
    func solve(_ board: inout [[Character]]) {
        boardHeight = board.count
        boardWidth = board[0].count
        
        checkBoardSides(&board, boardHeight: boardHeight, boardWidth: boardWidth)
        
        changeMarks(&board, height: boardHeight, width: boardWidth)
        print(board)
    }
    
    private func dfs(_ board: inout Board, row: Int, col: Int) {
        board[row][col] = markStar
        
        for direction in directions {
            let newRow = row + direction.0
            let newCol = col + direction.1
            
            if newRow < 0 || newCol < 0 || newRow >= boardHeight || newCol >= boardWidth || board[newRow][newCol] != markO {
                continue
            }
            
            dfs(&board, row: newRow, col: newCol)
        }
    }
    
    private func checkBoardSides(_ board: inout Board, boardHeight: Int, boardWidth: Int) {
        //Check Four Sides of board
        for row in 0..<boardHeight {
            //Check Board LeftSide
            if board[row][0] == markO {
                dfs(&board, row: row, col: 0)
            }
            //Check Board RightSide
            if board[row][boardWidth - 1] == markO {
                dfs(&board, row: row, col: boardWidth - 1)
            }
        }
        
        for col in 0..<boardWidth {
            //Check Board TopSide
            if board[0][col] == markO {
                dfs(&board, row: 0, col: col)
            }
            //Check Board BottomSide
            if board[boardHeight - 1][col] == markO {
                dfs(&board, row: boardHeight - 1, col: col)
            }
        }
    }
    
    private func changeMarks(_ board: inout Board, height: Int, width: Int) {
        for row in 0..<height {
            for col in 0..<width {
                if board[row][col] == markStar { board[row][col] = markO }
                else if board[row][col] == markO { board[row][col] = markX }
                else { board[row][col] = markX }
            }
        }
    }
}

let solution = Solution()
var board: Board = [["X","O","X","O","X","O"],["O","X","O","X","O","X"],["X","O","X","O","X","O"],["O","X","O","X","O","X"]]
solution.solve(&board)
