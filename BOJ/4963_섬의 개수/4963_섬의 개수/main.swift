import Foundation

// 동 서 남 북 동남 동북 서남 서북
let dx = [1, -1, 0, 0, 1, 1, -1, -1]
let dy = [0, 0, 1, -1, 1, -1, 1, -1]
var visited = [[Bool]]()
var islandMap = [[Int]]()
var width = 0
var height = 0

while true {
  
  let readNM = readLine()!.split(separator: " ").map({ Int($0)! })
  var landCount = 0
  
  width = readNM[0] // width
  height = readNM[1] // height
  
  if width == 0 && height == 0 { break }
  
  visited = [[Bool]](repeating: [Bool](repeating: false, count: width), count: height)
  islandMap = [[Int]](repeating: [Int](repeating: 0, count: width), count: height)
  
  for h in 0..<height {
    let readOneLine = readLine()!.split(separator: " ").map({ Int($0)! })
    for i in 0..<readOneLine.count {
      islandMap[h][i] = readOneLine[i]
    }
  }
  
  for h in 0..<height {
    for w in 0..<width {
      if visited[h][w] == false && islandMap[h][w] == 1 {
        landCount += 1
        dfs(y: h, x: w)
      }
    }
  }
  
  print(landCount)
}

func dfs(y: Int, x: Int) {
  // First Visit
  visited[y][x] = true
  
  for i in 0..<8 {
    let newY = y + dy[i]
    let newX = x + dx[i]
    
    //Check position is no out of map
    if 0 <= newX && 0 <= newY && newY < height && newX < width {
      //If new position is not visited and land -> DFS
      if visited[newY][newX] == false && islandMap[newY][newX] == 1 {
        dfs(y: newY, x: newX)
      }
    }
  }
}
