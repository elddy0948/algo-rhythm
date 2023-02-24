import Foundation

let readNM = readLine()!.components(separatedBy: " ").map({ Int($0)! })
let graphSize = readNM[0]
let sumSize = readNM[1]
var graph = [[Int]]()
var graphSum = [[Int]](repeating: [Int](repeating: 0, count: graphSize + 1), count: graphSize + 1)

for _ in 0 ..< graphSize {
  let graphLine = readLine()!.split(separator: " ").map{Int(String($0))!}
  graph.append(graphLine)
}

for i in 1 ... graphSize {
  for j in 1 ... graphSize {
    graphSum[i][j] = graphSum[i - 1][j] + graphSum[i][j - 1] - graphSum[i - 1][j - 1] + graph[i - 1][j - 1]
  }
}

for _ in 0 ..< sumSize {
  let input = readLine()!.split(separator: " ").map{Int(String($0))!}
  let x1 = input[0]; let x2 = input[2]
  let y1 = input[1]; let y2 = input[3]

  print(graphSum[x2][y2] - graphSum[x1 - 1][y2] - graphSum[x2][y1 - 1] + graphSum[x1 - 1][y1 - 1])
}
