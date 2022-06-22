import Foundation

/*
 * Complete the 'marcsCakewalk' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY calorie as parameter.
 */

func marcsCakewalk(calorie: [Int]) -> Int {
    // Write your code here
  // 2**j * c
  
  let sortedCalories = calorie.sorted(by: >)
  var answer = 0.0
  
  for j in 0..<calorie.count {
    let lhs = pow(Double(2.0), Double(j))
    let rhs = Double(sortedCalories[j])
    answer += lhs * rhs
  }
  
  return Int(answer)
}

guard let n = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

guard let calorieTemp = readLine()?.replacingOccurrences(of: "\\s+$", with: "", options: .regularExpression) else { fatalError("Bad input") }

let calorie: [Int] = calorieTemp.split(separator: " ").map {
    if let calorieItem = Int($0) {
        return calorieItem
    } else { fatalError("Bad input") }
}

guard calorie.count == n else { fatalError("Bad input") }

let result = marcsCakewalk(calorie: calorie)


print(result)
