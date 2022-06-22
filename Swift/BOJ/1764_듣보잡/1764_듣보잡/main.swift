import Foundation

let read = readLine()?.components(separatedBy: " ") ?? [""]
let N = Int(read[0])!
let M = Int(read[1])!

var notListen = Set<String>()
var notSeen = Set<String>()

for _ in 0..<N {
    let person = readLine() ?? ""
    notListen.insert(person)
}
for _ in 0..<M {
    let person = readLine() ?? ""
    notSeen.insert(person)
}
var notListenAndSeen = notListen.intersection(notSeen)
print(notListenAndSeen.count)
for person in notListenAndSeen.sorted() {
    print(person)
}
