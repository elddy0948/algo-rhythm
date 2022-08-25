//200. Number of Islands
import Foundation

class Solution {
    private var map = [[Character]]()
    private let directions: [(Int, Int)] = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    private var visited: [[Bool]]!
    private var mapHeight: Int!
    private var mapWidth: Int!
    private var landCount = 0
    
    func numIslands(_ grid: [[Character]]) -> Int {
        mapHeight = grid.count
        mapWidth = grid[0].count
        map = grid
        visited = Array<[Bool]>(repeating: Array<Bool>(repeating: false, count: mapWidth),
                                count: mapHeight)
        
        for row in 0..<mapHeight {
            for col in 0..<mapWidth {
                if map[row][col] == "1" && visited[row][col] == false {
                    dfs(row, col)
                    landCount += 1
                }
            }
        }
        
        return landCount
    }
    
    private func dfs(_ row: Int, _ col: Int) {
        visited[row][col] = true
        
        for direction in directions {
            let newRow = row + direction.0
            let newCol = col + direction.1

            if newRow < 0 || newCol < 0 || newRow >= mapHeight || newCol >= mapWidth
                || map[newRow][newCol] != "1" || visited[newRow][newCol] != false {
                continue
            }
            dfs(newRow, newCol)
        }
    }
}

let solution = Solution()

print(solution.numIslands([
    ["1","1","0","0","0"],
    ["1","1","0","0","0"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
  ]))
