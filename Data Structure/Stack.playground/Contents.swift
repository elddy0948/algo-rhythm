import UIKit

public struct JoonStack<T> {
    private var storage: [T] = []

    //push and pop
    public mutating func push(_ element: T) {
        storage.append(element)
    }
    
    @discardableResult
    public mutating func pop() -> T? {
        storage.popLast()
    }
    
    public func showStack() {
        let toPrint = storage.map { "\($0)" }.reversed().joined(separator: "\n")
        print(toPrint)
    }
}

var stack = JoonStack<String>()
stack.push("Joons")
stack.push("Hello")
stack.push("Swift")
stack.push("iOS")
stack.push("macOS")

stack.pop()
stack.showStack()
