import Foundation

/*
 * Complete the 'balancedSums' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

func balancedSums(arr: [Int]) -> String {
  // Write your code here
  var answer = "NO"
  var sumArr: [Int] = [0]
  let n = arr.count
  
  for i in 1...arr.count {
    let beforeNumber = sumArr[i - 1]
    sumArr.append(beforeNumber + arr[i - 1])
  }
  
  for midIndex in 0..<arr.count {
    if (sumArr[n] - sumArr[midIndex + 1]) == sumArr[midIndex] {
      answer = "YES"
      return answer
    }
  }
  
  return answer
}

guard let T = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

for TItr in 1...T {
  guard let n = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
  else { fatalError("Bad input") }
  
  guard let arrTemp = readLine()?.replacingOccurrences(of: "\\s+$", with: "", options: .regularExpression) else { fatalError("Bad input") }
  
  let arr: [Int] = arrTemp.split(separator: " ").map {
    if let arrItem = Int($0) {
      return arrItem
    } else { fatalError("Bad input") }
  }
  
  guard arr.count == n else { fatalError("Bad input") }
  
  let result = balancedSums(arr: arr)
  print(result)
}
