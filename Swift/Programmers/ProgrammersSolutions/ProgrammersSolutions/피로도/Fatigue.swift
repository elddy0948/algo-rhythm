import Foundation

final class Fatigue {
  
  var answer = 0
  
  func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    var visited = [Bool](repeating: false, count: dungeons.count + 1)

    backtracking(k, dungeons, &visited, 0)
    
    return answer
  }
  
  private func backtracking(_ current: Int, _ dungeons: [[Int]], _ visited: inout [Bool], _ visitedCount: Int) {
    for i in 0 ..< dungeons.count {
      if dungeons[i][0] <= current && !visited[i] {
        visited[i] = true
        backtracking(current - dungeons[i][1], dungeons, &visited, visitedCount + 1)
        visited[i] = false
      }
    }
    answer = max(answer, visitedCount)
    return
  }
}
