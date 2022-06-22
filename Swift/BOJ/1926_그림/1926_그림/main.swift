import Foundation

let readNM = readLine()!.split(separator: " ").map({ Int($0)! })
let n = readNM[0]
let m = readNM[1]

var board = [[Int]]()
var visited = [[Bool]](repeating: [Bool](repeating: false, count: m), count: n)
var paintCount = 0
var largestPaint = 0
let dx = [1, 0, -1, 0]
let dy = [0, 1, 0, -1]
var queue = Queue<(Int, Int)>()

for _ in 0 ..< n {
  let readLine = readLine()!.split(separator: " ").map({ Int($0)! })
  board.append(readLine)
}

for i in 0 ..< n {
  for j in 0 ..< m {
    if !visited[i][j] && board[i][j] == 1 {
      //방문하지 않은 곳 (그림의 시작점)
      paintCount += 1
      visited[i][j] = true
      queue.enqueue((i, j))
      bfs()
    }
  }
}

print(paintCount)
print(largestPaint)

func bfs() {
  var paintSize = 1
  
  while !queue.isEmpty {
    guard let current = queue.dequeue() else { return }
    let x = current.0
    let y = current.1
    
    for d in 0 ..< 4 {
      let nextX = x + dx[d]
      let nextY = y + dy[d]
      
      if nextX < 0 || nextX >= n || nextY < 0 || nextY >= m {
        continue
      }
      
      if visited[nextX][nextY] || board[nextX][nextY] != 1 {
        continue
      }
      
      visited[nextX][nextY] = true
      paintSize += 1
      queue.enqueue((nextX, nextY))
    }
  }
  
  largestPaint = max(paintSize, largestPaint)
}

//MARK: - Queue
struct Queue<T> {
  var leftStack: [T] = []
  var rightStack: [T] = []
  
  var isEmpty: Bool {
    return leftStack.isEmpty && rightStack.isEmpty
  }
  
  @discardableResult
  mutating func enqueue(_ element: T) -> Bool {
    rightStack.append(element)
    return true
  }
  
  mutating func dequeue() -> T? {
    if leftStack.isEmpty {
      leftStack = rightStack.reversed()
      rightStack.removeAll()
    }
    
    return leftStack.popLast()
  }
}
