import Foundation

var network = [Int]()
var coms = [[Int]]()

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
  network = [Int](repeating: -1, count: n)
  coms = computers
  
  for computer in 0 ..< n {
    if network[computer] == -1 {
      dfs(computerNumber: computer, networkNumber: computer)
    } else {
      dfs(computerNumber: computer, networkNumber: network[computer])
    }
  }
  
  return Set(network).count
}

func dfs(computerNumber: Int, networkNumber: Int) {
  network[computerNumber] = networkNumber
  
  for nextComputer in 0 ..< network.count {
    if computerNumber == nextComputer { continue }
    if network[nextComputer] == networkNumber { continue }
    
    if coms[computerNumber][nextComputer] == 1 {
      dfs(computerNumber: nextComputer, networkNumber: networkNumber)
    }
  }
}


print(solution(4, [[1,1,0,1], [1,1,0,0], [0,0,1,1], [1,0,1,1]]))
