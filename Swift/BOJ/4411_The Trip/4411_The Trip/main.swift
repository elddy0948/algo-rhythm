import Foundation

while let read = readLine() {
    if read == "0" {break}
    var students: [Int] = Array<Int>()
    var sum = 0
    let readN = Int(read)!
    for _ in 0..<readN {
        let readDollar = readLine()?.components(separatedBy: ".")
        let frontDollar = Int(readDollar?[0] ?? "") ?? 0
        let backDollar = Int(readDollar?[1] ?? "") ?? 0
        let dollar = frontDollar * 100 + backDollar
        students.append(dollar)
        sum += dollar
    }
    let lowerAvg = sum / readN
    let higherAvg = lowerAvg + ((sum % readN != 0) ? 1 : 0)
    var low = 0, high = 0
    for money in students {
        if money < lowerAvg { low += lowerAvg - money }
        else if money > higherAvg { high += money - higherAvg }
    }
    let answer = max(low, high)
    var stringDollar = "$" + String(answer / 100) + "."
    if answer % 100 < 10 {
        stringDollar += "0"
    }
    stringDollar += String(answer % 100)
    print(stringDollar)
}
