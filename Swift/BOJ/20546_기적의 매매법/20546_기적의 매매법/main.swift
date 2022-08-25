import Foundation

struct Person {
    var totalMoney: Int
    var totalStock: Int
    
    mutating func buyStock(stock: Int, money: Int) {
        totalMoney = money
        totalStock += stock
    }
    mutating func soldStock(total: Int) {
        totalMoney = total
        totalStock = 0
    }
}

guard let readTotalMoney = readLine() else {
    fatalError()
}

let readStockPrice = readLine()!.split(separator: " ").map { Int($0)! }

var junHyun = Person(totalMoney: Int(readTotalMoney)!, totalStock: 0)
var sungMin = Person(totalMoney: Int(readTotalMoney)!, totalStock: 0)
var longCount = 0
var shortCount = 0

for i in 0..<readStockPrice.count {
    if junHyun.totalMoney / readStockPrice[i] != 0 {
        //buy junhyun
        junHyun.buyStock(stock: junHyun.totalMoney / readStockPrice[i], money: junHyun.totalMoney % readStockPrice[i])
    }
    
    if i == 0 {
        longCount = 1
        shortCount = 1
        continue
    }
    
    if longCount == 3 && sungMin.totalStock != 0 {
        sungMin.soldStock(total: sungMin.totalStock * readStockPrice[i])
        longCount = 1
        shortCount = 1
    } else if shortCount == 3 && sungMin.totalMoney / readStockPrice[i] != 0 {
        //전량매도
        sungMin.buyStock(stock: sungMin.totalMoney / readStockPrice[i], money: sungMin.totalMoney % readStockPrice[i])
        longCount = 1
        shortCount = 1
    }
    
    if longCount == 3 || shortCount == 3 {
        longCount = 1
        shortCount = 1
    }
    
    if readStockPrice[i - 1] < readStockPrice[i] {
        longCount += 1
        shortCount = 1
    } else if readStockPrice[i - 1] > readStockPrice[i] {
        shortCount += 1
        longCount = 1
    } else if readStockPrice[i - 1] == readStockPrice[i] {
        shortCount = 1
        longCount = 1
    }
}
let lastJunHyunMoney = (junHyun.totalStock * readStockPrice.last!) + junHyun.totalMoney
let lastSungMinMoney = (sungMin.totalStock * readStockPrice.last!) + sungMin.totalMoney

if lastSungMinMoney == lastJunHyunMoney {
    print("SAMESAME")
} else if lastJunHyunMoney > lastSungMinMoney {
    print("BNP")
} else if lastSungMinMoney > lastJunHyunMoney {
    print("TIMING")
}
