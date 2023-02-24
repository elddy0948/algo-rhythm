import Foundation

let read = readLine()!.components(separatedBy: " ").map({ Int($0)! })
let n = read[0]
let s = read[1]

let numbers = readLine()!.components(separatedBy: " ").map({ Int($0)! })

var end = 0
var minLength = Int.max
var sum  = numbers[0]

for start in 0 ..< n {
  while end < n && sum < s {
    end += 1
    if end != n { sum += numbers[end] }
  }
  if end == n { break }
  minLength = min(minLength, end - start + 1)
  sum -= numbers[start]
}

if minLength == Int.max { print(0) }
else { print(minLength) }
