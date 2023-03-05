import Foundation

let readNM = readLine()!.split(separator: " ").map({ Int(String($0))! })
let n = readNM[0]
let m = readNM[1]

let numbers = readLine()!.split(separator: " ").map({ Int(String($0))! })
var sums = [Int](repeating: 0, count: n + 1)
var remainders = [Int](repeating: 0, count: m)

for i in 1 ... n {
  sums[i] = sums[i - 1] + numbers[i - 1]
  let remainder = sums[i] % m

  remainders[remainder] += 1
}

var result: Int = remainders[0]

for i in 0 ..< m {
  let temp = remainders[i] * (remainders[i] - 1) / 2
  result += temp
}

print(result)