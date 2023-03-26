// Level 1 . 제일 작은 수 제거하기

import Foundation

func solution(_ arr: [Int]) -> [Int] {
  var temp = arr
  let minNumber = temp.min() ?? 0
  guard let index = temp.firstIndex(where: { $0 == minNumber} ) else {
    return [-1]
  }
  temp.remove(at: index)
  if temp.isEmpty { return [-1] }
  return temp
}
