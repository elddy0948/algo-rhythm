// Level 1 - [카카오 인턴] 키패드 누르기

import Foundation

func solution(_ numbers:[Int], _ hand:String) -> String {
  // -1 : Left / 1 : Right
  let positionBuffer = createPositionBuffer()
  var lhsPosition = (3, 0)
  var rhsPosition = (3, 2)
  var answer = ""
  
  for number in numbers {
    if isLeftSide(number) {
      lhsPosition = positionBuffer[number]
      answer.append("L")
    } else if isRightSide(number) {
      rhsPosition = positionBuffer[number]
      answer.append("R")
    } else {
      let target = positionBuffer[number]
      let lhsDistance = calculateDistance(from: lhsPosition, to: target)
      let rhsDistance = calculateDistance(from: rhsPosition, to: target)
      if lhsDistance < rhsDistance { lhsPosition = target; answer.append("L") }
      else if lhsDistance > rhsDistance { rhsPosition = target; answer.append("R") }
      else if lhsDistance == rhsDistance {
        if hand == "right" { rhsPosition = target; answer.append("R") }
        else { lhsPosition = target; answer.append("L") }
      }
    }
  }
  
  return answer
}

func isLeftSide(_ number: Int) -> Bool {
  return number == 1 || number == 4 || number == 7
}

func isRightSide(_ number: Int) -> Bool {
  return number == 3 || number == 6 || number == 9
}

func createPositionBuffer() -> [(Int, Int)] {
  var positionBuffer = [(Int, Int)](repeating: (0, 0), count: 10)
  positionBuffer[0] = (3, 1)
  for number in 1 ... 9 {
    let y = (number - 1) % 3
    let x = (number - 1) / 3
    
    positionBuffer[number] = (x, y)
  }
  return positionBuffer
}

func calculateDistance(from current: (Int, Int), to target: (Int, Int)) -> Int {
  let row = abs(current.0 - target.0)
  let col = abs(current.1 - target.1)
  return row + col
}
