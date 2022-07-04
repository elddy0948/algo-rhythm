import Foundation

class Solution10026 {
  var visited = [[Bool]](repeating: [Bool](repeating: false, count: 101), count: 101)
  var rgbMap = [[String]]()
  var mapWidth = 0
  var mapHeight = 0
  
  let dx: [Int] = [1, 0, -1, 0]
  let dy: [Int] = [0, 1, 0, -1]
  
  func dfs(y: Int, x: Int, color: String, isColorWeakness: Bool) {
    
    visited[y][x] = true
    
    for i in 0 ..< 4 {
      let nextX = x + dx[i]
      let nextY = y + dy[i]
      
      if nextX >= 0 && nextY >= 0 && nextX < mapWidth && nextY < mapHeight {
        if isColorWeakness {
          if color == "R" || color == "G" {
            if (rgbMap[nextY][nextX] == "R" || rgbMap[nextY][nextX] == "G") && !visited[nextY][nextX] {
              dfs(y: nextY, x: nextX, color: color, isColorWeakness: isColorWeakness)
            }
          } else {
            if rgbMap[nextY][nextX] == color && !visited[nextY][nextX] {
              dfs(y: nextY, x: nextX, color: color, isColorWeakness: isColorWeakness)
            }
          }
        } else {
          if rgbMap[nextY][nextX] == color && !visited[nextY][nextX] {
            dfs(y: nextY, x: nextX, color: color, isColorWeakness: isColorWeakness)
          }
        }
      }
    }
  }
  
  func solve() {
    let n = Int(readLine()!)!
    var answer: (Int, Int) = (0, 0)
    
    for _ in 0 ..< n {
      let line = readLine()!.map({ String($0) })
      rgbMap.append(line)
    }
    
    mapWidth = rgbMap[0].count
    mapHeight = rgbMap.count
    
    for i in 0 ..< mapHeight {
      for j in 0 ..< mapWidth {
        if !visited[i][j] {
          dfs(y: i, x: j, color: rgbMap[i][j], isColorWeakness: false)
          answer.0 += 1
        }
      }
    }
    
    visited = [[Bool]](repeating: [Bool](repeating: false, count: 101), count: 101)
    
    for i in 0 ..< mapHeight {
      for j in 0 ..< mapWidth {
        if !visited[i][j] {
          dfs(y: i, x: j, color: rgbMap[i][j], isColorWeakness: true)
          answer.1 += 1
        }
      }
    }
    
    print("\(answer.0) \(answer.1)")
  }
}
