import Foundation

let readInput = readLine()!.split(separator: " ").map({ Int($0)! })

let a = readInput[0]
let b = readInput[1]
let c = readInput[2]

func pow(a: Int, b: Int, n: Int) -> Int {
  if b == 1 { return a % n }
  
  var val = pow(a: a, b: b / 2, n: n)
  
  val = val * val % n
  
  if b % 2 == 0 { return val }
  
  return val * a % n
}

print(pow(a: a, b: b, n: c))
