import Foundation

guard let readComputerCount = Int(readLine() ?? "") else {
    fatalError()
}

guard let readEdgeCount = Int(readLine() ?? "") else {
    fatalError()
}

var computers = [[Int]]()
var visited = [Bool]()
var queue = [Int]()
var answer = 0

for _ in 0..<readComputerCount {
    computers.append([])
    visited.append(false)
}

for _ in 0..<readEdgeCount {
    let readVertex = readLine()!.split(separator: " ").map { Int($0)! }
    computers[readVertex[0] - 1].append(readVertex[1] - 1)
    computers[readVertex[1] - 1].append(readVertex[0] - 1)
}

queue.append(0)

while !queue.isEmpty {
    let vertex = queue.removeFirst()
    if visited[vertex] {
        continue
    }
    visited[vertex] = true
    answer += 1
    
    for computer in computers[vertex] {
        if !visited[computer] {
            queue.append(computer)
        }
    }
}

print(answer - 1)
