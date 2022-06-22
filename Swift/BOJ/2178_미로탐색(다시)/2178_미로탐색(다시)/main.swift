import Foundation

let readNM = readLine()!.split(separator: " ").map({ Int($0)! })
let n = readNM[0]
let m = readNM[1]

var maze = [[Int]]()
var distanceFromStart = [[Int]](repeating: [Int](repeating: -1, count: m), count: n)
var mazeQueue = Queue<(Int, Int)>()
let dx = [1, 0, -1, 0]
let dy = [0, 1, 0, -1]

for _ in 0 ..< n {
  let readMaze = readLine()!.map({ Int(String($0))! })
  maze.append(readMaze)
}

//0,0에서 출발
distanceFromStart[0][0] = 1
mazeQueue.enqueue((0, 0))

bfs()

print(distanceFromStart[n - 1][m - 1])

func bfs() {
  while !mazeQueue.isEmpty {
    guard let current = mazeQueue.dequeue() else { return }
    
    let x = current.0
    let y = current.1
    
    for d in 0 ..< 4 {
      let newX = x + dx[d]
      let newY = y + dy[d]
      
      if newX < 0 || newX >= n || newY < 0 || newY >= m {
        continue
      }
      
      if distanceFromStart[newX][newY] != -1 || maze[newX][newY] != 1 {
        continue
      }
      
      distanceFromStart[newX][newY] = distanceFromStart[x][y] + 1
      mazeQueue.enqueue((newX, newY))
    }
  }
}



//MARK: - Queue
struct Queue<T> {
  var leftStack = [T]()
  var rightStack = [T]()
  
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
