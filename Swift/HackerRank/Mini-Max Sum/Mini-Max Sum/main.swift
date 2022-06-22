import Foundation

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

func miniMaxSum(arr: [Int]) -> Void {
  // Write your code here
  
  let sortedArray = arr.sorted()
  let sumOfArray = sortedArray.reduce(0, +)
  
  print("\(sumOfArray - (sortedArray.max() ?? 0)) \(sumOfArray - (sortedArray.min() ?? 0))")
  
}

guard let arrTemp = readLine()?.replacingOccurrences(of: "\\s+$", with: "", options: .regularExpression) else { fatalError("Bad input") }

let arr: [Int] = arrTemp.split(separator: " ").map {
  if let arrItem = Int($0) {
    return arrItem
  } else { fatalError("Bad input") }
}

guard arr.count == 5 else { fatalError("Bad input") }

miniMaxSum(arr: arr)
