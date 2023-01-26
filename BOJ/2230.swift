import Foundation

let line = readLine()!.components(separatedBy: " ").map({ Int($0)! })

let n = line[0]
let m = line[1]

var arr = [Int](repeating: 0, count: n)

for i in 0 ..< n {
  let readNumber = Int(readLine()!)!
  arr[i] = readNumber
}

var end = 0
var answer = Int.max

arr.sort()

for start in 0 ..< n {
  while end < n && arr[end] - arr[start] < m {
    end += 1
  }
  if end == n { break }
  answer = min(answer, arr[end] - arr[start])
}

print(answer)