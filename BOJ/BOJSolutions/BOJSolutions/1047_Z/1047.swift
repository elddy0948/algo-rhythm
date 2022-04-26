import Foundation

final class Solution1047 {
  func recursion(n: Int, row: Int, col: Int) -> Int {
    
    if n == 0 { return 0 }
    let half = 1 << (n - 1)
    
    if row < half && col < half { return recursion(n: n - 1, row: row, col: col) }
    if row < half && col >= half { return half * half + recursion(n: n - 1, row: row, col: col - half)}
    if row >= half && col < half { return 2 * half * half + recursion(n: n - 1, row: row - half, col: col)}
    if row >= half && col >= half { return 3 * half * half + recursion(n: n - 1, row: row - half, col: col - half)}
    
    return 0
  }
  
  func solve() {
    let readNRC = readLine()!.split(separator: " ").map({ String($0) })
    
    let n = Int(readNRC[0])!
    let r = Int(readNRC[1])!
    let c = Int(readNRC[2])!
    
    print(recursion(n: n, row: r, col: c))
  }
}
