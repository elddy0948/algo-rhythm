import Foundation

let readNumber = readLine() ?? "1"

func solution(_ number: String) -> Int {
  guard let intNumber = Int(number),
        intNumber >= 100 else {
          return Int(number)!
        }
  
  let answer = 99
  
  let array = (100 ... intNumber).map({ number -> [String] in
    let stringNumber = String(number)
    return Array(stringNumber).map({ String($0) })
  }).filter({ singleNumber in
    let lhs = (Int(singleNumber[1]) ?? 0) - (Int(singleNumber[0]) ?? 0)
    let rhs = (Int(singleNumber[2]) ?? 0) - (Int(singleNumber[1]) ?? 0)
    
    if lhs == rhs { return true }
    else { return false }
  })
  
  return answer + array.count
}

print(solution(readNumber))
