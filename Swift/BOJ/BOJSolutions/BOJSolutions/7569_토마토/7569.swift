import Foundation

final class Solution7569 {
  typealias TomatoPosition = (level: Int, y: Int, x: Int)
  
  var boxRow = 0
  var boxCol = 0
  var boxLevel = 0
  
  let directions = [(0, 0, 1), (0, 0, -1), (1, 0, 0), (-1, 0, 0), (0, 1, 0), (0, -1, 0)] //오른쪽 왼쪽 아래 위 앞 뒤
  var tomatoBoxes = [[[Int]]]()
  var queue = [TomatoPosition]()
  var maxDate = -1
  var tomatoFilled = 0
  var tomatoToFilled = 0
  
  func bfs() {
    var index = 0
    
    while index < queue.count {
      let current = queue[index]
      index += 1
      
      for i in 0 ..< 6 {
        let nextX = current.x + directions[i].2
        let nextY = current.y + directions[i].1
        let nextLevel = current.level + directions[i].0
        
        if nextX >= 0 && nextY >= 0 && nextLevel >= 0 && nextX < boxRow && nextY < boxCol && nextLevel < boxLevel {
          if tomatoBoxes[nextLevel][nextY][nextX] == 0 {
            queue.append((nextLevel, nextY, nextX))
            tomatoFilled += 1
            let date = tomatoBoxes[current.level][current.y][current.x] + 1
            maxDate = max(maxDate, date)
            tomatoBoxes[nextLevel][nextY][nextX] = date
          }
        }
      }
    }
  }
  
  func solve() {
    let readInfo = readLine()!.components(separatedBy: " ").map({ Int($0)! })
    
    boxRow = readInfo[0]
    boxCol = readInfo[1]
    boxLevel = readInfo[2]
    
    for _ in 0 ..< boxLevel {
      var tomatoBox = [[Int]]()
      
      for _ in 0 ..< boxCol {
        let boxRow = readLine()!.components(separatedBy: " ").map({ Int($0)! })
        tomatoBox.append(boxRow)
      }
      
      tomatoBoxes.append(tomatoBox)
    }
    
    for l in 0 ..< boxLevel {
      for i in 0 ..< boxCol {
        for j in 0 ..< boxRow {
          if tomatoBoxes[l][i][j] == 1 {
            queue.append((l, i, j))
          } else if tomatoBoxes[l][i][j] == 0 {
            tomatoToFilled += 1
          }
        }
      }
    }
    
    if tomatoToFilled == 0 { print(0) }
    else {
      bfs()
      tomatoFilled == tomatoToFilled ? print(maxDate - 1) : print(-1)
    }
  }
}
