import Foundation

guard let readLine = readLine() else {
    fatalError()
}

var binaryNumber =  ""
var firstFlag = true

for single in readLine {
    let singleBinary = String(Int(String(single))!, radix: 2, uppercase: false)
    if singleBinary.count == 1 && !firstFlag {
        binaryNumber.append("00" + singleBinary)
    } else if singleBinary.count == 2 && !firstFlag {
        binaryNumber.append("0" + singleBinary)
    } else {
        binaryNumber.append(singleBinary)
    }
    firstFlag = false
}
print(binaryNumber)
