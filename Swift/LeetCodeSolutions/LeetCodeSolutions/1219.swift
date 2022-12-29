import Foundation

class Solution1219 {
  let directions: [(Int, Int)] = [
    (0, 1), (1, 0), (0, -1), (-1, 0)
  ]
  
  func getMaximumGold(_ grid: [[Int]]) -> Int {
    var result = 0
    var variableGrid = grid
    
    for i in 0 ..< grid.count {
      for j in 0 ..< grid[i].count {
        if grid[i][j] > 0 {
          result = max(result, backtracking(&variableGrid, i, j))
        }
      }
    }
    
    return result
  }
  
  private func backtracking(_ grid: inout [[Int]], _ y: Int, _ x: Int) -> Int {
    var result = 0
    grid[y][x] *= -1 // mark visited
    
    for direction in directions {
      let nextX = x + direction.0
      let nextY = y + direction.1
      
      if nextX >= 0 && nextX < grid[0].count && nextY >= 0 && nextY < grid.count && grid[nextY][nextX] > 0 {
        result = max(result, backtracking(&grid, nextY, nextX))
      }
    }
    
    grid[y][x] *= -1
    
    return grid[y][x] + result
  }
}
