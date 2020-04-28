import Foundation

struct myStack<Int> {
    var array = [Int]()
    var empty: Bool {
        return array.isEmpty
    }
    var size: Int {
        return array.count as! Int
    }
    mutating func push(_ n: Int) {
        array.append(n)
    }
    mutating func pop() -> Int? {
        return array.popLast()
    }
    var top: Int? {
        return array.last
    }
}
let commandLine = readLine() ?? ""
var stack = myStack<Int>()
for _ in 0..<(Int(commandLine))! {
    let read = readLine()?.components(separatedBy: " ") ?? [""]
    let command = read[0]
    switch command {
    case "push":
        let number = Int(read[1]) ?? 0
        stack.push(number)
        break
    case "pop":
        if stack.empty { print("-1") }
        else { print(stack.pop()!) }
        break
    case "size":
        print(stack.size)
    case "top":
        if stack.empty { print("-1") }
        else { print(stack.top!) }
        break
    case "empty":
        if stack.empty {print("1")}
        else {print("0")}
        break
    default:
        break
    }
}
