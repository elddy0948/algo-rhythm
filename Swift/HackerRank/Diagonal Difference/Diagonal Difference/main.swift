import Foundation

/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

func diagonalDifference(arr: [[Int]]) -> Int {
  
  let rightLeft = [1, 1]
  let leftRight = [1, -1]
  
  var sumRightToLeft = 0
  var sumLeftToRight = 0
  
  //Right to Left
  // +1, +1
  sumRightToLeft = calculateDiagonals((0, 0), rightLeft, arr)
  
  //Left to Right
  // +1, -1
  sumLeftToRight = calculateDiagonals((0, arr.count - 1), leftRight, arr)
  
  
  return abs(sumRightToLeft - sumLeftToRight)
}

func calculateDiagonals(_ start: (Int, Int), _ positionChange: [Int], _ arr: [[Int]]) -> Int {
  var w = start.1
  var h = start.0
  var sum = 0
  
  for _ in 0 ..< arr.count {
    sum += arr[h][w]
    
    w += positionChange[1]
    h += positionChange[0]
  }
  
  return sum
}

guard let n = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

var arr = [[Int]]()

for _ in 1...n {
    guard let arrRowTemp = readLine()?.replacingOccurrences(of: "\\s+$", with: "", options: .regularExpression) else { fatalError("Bad input") }

    let arrRow: [Int] = arrRowTemp.split(separator: " ").map {
        if let arrItem = Int($0) {
            return arrItem
        } else { fatalError("Bad input") }
    }

    guard arrRow.count == n else { fatalError("Bad input") }

    arr.append(arrRow)
}

guard arr.count == n else { fatalError("Bad input") }

let result = diagonalDifference(arr: arr)

print(result)
