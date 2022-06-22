import Foundation

let tx = [-1, 1, 0, 0]
let ty = [0, 0, -1, 1]

func BFS(_ x: Int, _ y: Int, _ cabbageGarden: inout [[Int]]) {
    var queue = [(x, y)]
    cabbageGarden[x][y] = 0
    
    while !queue.isEmpty {
        let vertex = queue.removeFirst()
        let nowXPos = vertex.0
        let nowYPos = vertex.1
        
        for i in 0..<4 {
            let moveX = nowXPos + tx[i]
            let moveY = nowYPos + ty[i]
            if moveX < 0 || moveY < 0 || moveX >= cabbageGarden.count || moveY >= cabbageGarden[0].count {
                continue
            }
            if cabbageGarden[moveX][moveY] == 0 {
                continue
            }
            cabbageGarden[moveX][moveY] = 0
            queue.append((moveX, moveY))
        }
    }
}

let testCase = Int(readLine()!)!
var width = 0
var height = 0
var cabbageLocationCount = 0

for _ in 0..<testCase {
    var answer = 0
    let cabbageInfo = readLine()!.split(separator: " ").map { Int($0)! }
    width = cabbageInfo[0]
    height = cabbageInfo[1]
    cabbageLocationCount = cabbageInfo[2]
    
    var cabbageGarden = [[Int]](repeating: [Int](repeating: 0, count: width), count: height)
    
    for _ in 0..<cabbageLocationCount {
        let cabbageLocation = readLine()!.split(separator: " ").map { Int($0)! }
        cabbageGarden[cabbageLocation[1]][cabbageLocation[0]] = 1
    }
    
    for i in cabbageGarden.indices {
        for j in cabbageGarden[i].indices {
            if cabbageGarden[i][j] == 0 {
                continue
            } else {
                answer += 1
                BFS(i, j, &cabbageGarden)
            }
        }
    }
    print(answer)
}
