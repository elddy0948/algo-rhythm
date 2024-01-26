// Level 1 - 최대공약수와 최소공배수

import Foundation

func solution(_ n:Int, _ m:Int) -> [Int] {
  return [gcd(n, m), lcm(n, m)]
}

func gcd(_ lhs: Int, _ rhs: Int) -> Int {
  return rhs == 0 ? lhs : gcd(rhs, lhs % rhs)
}

func lcm(_ lhs: Int, _ rhs: Int) -> Int {
  return lhs * rhs / gcd(lhs, rhs)
}
