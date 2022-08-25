import Foundation

var maze = [[Int]]()
var searchMaze: [[Int]] = [[Int]](repeating: [Int](repeating: 0, count: 101), count: 101)

let dx = [0,0,1,-1]
let dy = [1,-1,0,0]


func BFS(_ N: Int, _ M: Int) {
    var q: [(x: Int, y: Int)] = [(0, 0)]
    searchMaze[0][0] = 1
    while !q.isEmpty {
        let x = q.first!.x
        let y = q.first!.y
        q.removeFirst() //queue pop
        //4방향 이동하며 탐색
        for i in 0..<4 {
            let nextX = x + dx[i]
            let nextY = y + dy[i]
            //미로를 탈출해버리는 경우
            if 0 > nextX || nextX >= N || nextY < 0 || nextY >= M { continue }
            //이동할 수 없는 칸
            if searchMaze[nextX][nextY] != 0 || maze[nextX][nextY] == 0 { continue }
            q.append((nextX, nextY))
            searchMaze[nextX][nextY] = searchMaze[x][y] + 1
        }
    }
}

let read = readLine()?.components(separatedBy: " ")
let N = Int(read?[0] ?? "") ?? 0
let M = Int(read?[1] ?? "") ?? 0

for i in 0..<N {
    let a = readLine() ?? ""
    maze.append([Int]())
    for num in a {
        maze[i].append(num.wholeNumberValue!)
    }
}
BFS(N, M)
print(searchMaze[N - 1][M - 1])
