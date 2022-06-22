import Foundation

func maxProfit(_ prices: [Int]) -> Int {
    
    guard prices.count >= 1 else {return 0}
    
    var prof = Int.min
    var l = 0   //left
    var r = 0   //right
    
    for i in 1..<prices.count {
        if prices[i] < prices[r] {
            l = (prices[l] < prices[i]) ? l : i
            r = i
        } else {
            r = i
            prof = max(prof, (prices[r] - prices[l]))
        }
    }
    
    prof = max(prof, (prices[r] - prices[l]))
    
    return prof
}


print(maxProfit([7,1,5,3,6,4]))
