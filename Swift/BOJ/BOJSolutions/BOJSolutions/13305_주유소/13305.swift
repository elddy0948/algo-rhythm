import Foundation

class Solution13305 {
  func solve() {
    let cityCount = Int(readLine()!)!
    let roadLengths = readLine()!.split(separator: " ").map({ Int($0)! })
    let oilPrices = readLine()!.split(separator: " ").map({ Int($0)! })
    
    let minOilPrice = oilPrices.min() ?? 0
    var currentOilPrice = oilPrices[0]
    var totalOilRequired = 0
    
    if currentOilPrice == minOilPrice {
      let totalRoadLength = roadLengths.reduce(0, { $0 + $1 })
      print(totalRoadLength * currentOilPrice)
    } else {
      for (index, oilPrice) in oilPrices.enumerated() {
        if index == oilPrices.count - 1 { continue }
        if oilPrice < currentOilPrice {
          currentOilPrice = oilPrice
        }
        
        totalOilRequired += (roadLengths[index] * currentOilPrice)
      }
      print(totalOilRequired)
    }
  }
}
