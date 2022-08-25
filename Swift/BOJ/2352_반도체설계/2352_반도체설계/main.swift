import Foundation

let N = Int(readLine() ?? "") ?? 0
let nPort = readLine()!.split(separator: " ").map {Int($0)!}
var ans = [Int]()

extension Array where Element == Int {
  func lowerBound(_ val: Int) -> Int {
    var l = 0
    var r = self.count - 1
    while l <= r {
      let mid = (l + r) / 2
      if mid >= self.count { break }
      if self[mid] > val {
        r = mid - 1
      } else {
        l = mid + 1
      }
    }
    return l
  }
}

for i in nPort.indices {
    let ind = ans.lowerBound(nPort[i])
    if ind < ans.count {
        ans[ind] = nPort[i]
    } else {
        ans.append(nPort[i])
    }
}
print(ans.count)
