import Foundation


guard let readLine = readLine() else {
    fatalError()
}

var alphabetDictionary: [Character : Int] = [:]
let alphabetString = "abcdefghijklmnopqrstuvwxyz"
let alphabetArray = Array(alphabetString)
let inputArray = Array(readLine)
var answer: String = ""

for alphabet in alphabetArray {
    alphabetDictionary[alphabet] = -1
}

for i in 0..<inputArray.count {
    if alphabetDictionary[inputArray[i]]! == -1 {
        alphabetDictionary[inputArray[i]] = i
    }
}
alphabetArray.map { answer.append("\(alphabetDictionary[$0]!) ") }
print(answer)
