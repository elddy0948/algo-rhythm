import Foundation


func maxProfit(_ prices: [Int]) -> Int {
    //수익을 극대화 하려면 2일내에 파는것이 이득이다.
    var maxPro = 0
    
    for i in 0..<prices.count - 1 {
        if prices[i + 1] > prices[i] {
            maxPro += (prices[i + 1] - prices[i])
        }
    }
    return maxPro
}

print(maxProfit([7,1,5,3,6,4]))
