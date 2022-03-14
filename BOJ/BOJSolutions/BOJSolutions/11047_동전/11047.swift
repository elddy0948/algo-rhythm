import Foundation

class Solution11047 {
  func solve() {
    let readNK = readLine()!.split(separator: " ").map({ Int($0)! })
    let n = readNK[0]
    var k = readNK[1]
    var coinNeeds = 0
    var coins = [Int]()
    
    //오름차순으로 주어진다.
    for _ in 0 ..< n {
      let readCoin = Int(readLine()!)!
      coins.append(readCoin)
    }
    
    coins = coins.reversed()
    
    for coin in coins {
      if k < coin { continue }
      coinNeeds += (k / coin)
      k %= coin
    }
    
    print(coinNeeds)
  }
}
