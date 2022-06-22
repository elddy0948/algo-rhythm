import Foundation

let readN = Int(readLine()!)!
var answer = 0

func solution(_ n: Int) -> Int {
  guard n > 0 else { return 0 }
  
  var cols = [Int]()
  
  cols.reserveCapacity(n)
  
  dfs(n: n, cols: &cols)
  
  return answer
}

print(solution(readN))

func dfs(n: Int, cols: inout [Int]) {
  if cols.count == n {
    answer += 1
    return
  }
  
  for i in 0 ..< n {
    guard isValid(cols: cols, colIndex: i) else { continue }
    cols.append(i)
    dfs(n: n, cols: &cols)
    cols.removeLast()
  }
}


func isValid(cols: [Int], colIndex: Int) -> Bool {
  for rowIndex in 0 ..< cols.count {
    if colIndex == cols[rowIndex] { return false }
    if cols.count - rowIndex == colIndex - cols[rowIndex] { return false }
    if rowIndex - cols.count == colIndex - cols[rowIndex] { return false }
  }
  return true
}
