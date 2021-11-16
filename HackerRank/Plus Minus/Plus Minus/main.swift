import Foundation

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

func plusMinus(arr: [Int]) -> Void {
  // Write your code here
  
  var positiveNumber = 0
  var negativeNumber = 0
  var zero = 0
  
  _ = arr.map({ number in
    if number > 0 { positiveNumber += 1 }
    else if number < 0 { negativeNumber += 1 }
    else { zero += 1 }
  })
  
  let positiveRatio = Double(positiveNumber) / Double(arr.count)
  let negativeRatio = Double(negativeNumber) / Double(arr.count)
  let zeroRatio = Double(zero) / Double(arr.count)
  
  print(String(format: "%.6f", positiveRatio))
  print(String(format: "%.6f", negativeRatio))
  print(String(format: "%.6f", zeroRatio))
}

guard let n = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

guard let arrTemp = readLine()?.replacingOccurrences(of: "\\s+$", with: "", options: .regularExpression) else { fatalError("Bad input") }

let arr: [Int] = arrTemp.split(separator: " ").map {
  if let arrItem = Int($0) {
    return arrItem
  } else { fatalError("Bad input") }
}

guard arr.count == n else { fatalError("Bad input") }

plusMinus(arr: arr)
