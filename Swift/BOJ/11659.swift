import Foundation

let readNM = readLine()!.components(separatedBy: " ").map({ Int($0)! })
let n = readNM[0]
let m = readNM[1]

let numbers = readLine()!.components(separatedBy: " ").map({ Int($0)! })
var sums = [Int](repeating: 0, count: n + 1)

for num in 0 ..< numbers.count {
  sums[num + 1] = sums[num] + numbers[num]
}

for _ in 0 ..< m {
  let readRange = readLine()!.components(separatedBy: " ").map({ Int($0)! })
  print(sums[readRange[1]] - sums[readRange[0] - 1])
}
