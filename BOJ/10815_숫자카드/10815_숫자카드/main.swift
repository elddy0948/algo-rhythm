import Foundation

var answer = "";
let _ = readLine()
let cardArray = readLine()!.split(separator: " ").map { String($0) }
var dic = [String:Int]()

for i in cardArray.indices {
    dic[cardArray[i]] = 1
}

let _ = readLine()
let cardToFindArray = readLine()!.split(separator: " ").map { String($0) }
let len = cardToFindArray.count

for i in cardToFindArray.indices {
    if dic[cardToFindArray[i]] == nil {
        answer += "0"
    } else {
        answer += "1"
    }
    if i != len-1 {
        answer += " "
    }
}

print(answer)
