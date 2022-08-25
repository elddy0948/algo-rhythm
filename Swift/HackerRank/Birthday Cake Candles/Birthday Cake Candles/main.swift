import Foundation

/*
 * Complete the 'birthdayCakeCandles' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY candles as parameter.
 */

func birthdayCakeCandles(candles: [Int]) -> Int {
    // Write your code here
  let highest = candles.max() ?? 0
  let filteredCandles = candles.filter({ $0 == highest })
  return filteredCandles.count
}

guard let candlesCount = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

guard let candlesTemp = readLine()?.replacingOccurrences(of: "\\s+$", with: "", options: .regularExpression) else { fatalError("Bad input") }

let candles: [Int] = candlesTemp.split(separator: " ").map {
    if let candlesItem = Int($0) {
        return candlesItem
    } else { fatalError("Bad input") }
}

guard candles.count == candlesCount else { fatalError("Bad input") }

let result = birthdayCakeCandles(candles: candles)
print(result)
