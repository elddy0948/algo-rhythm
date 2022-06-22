import Foundation

public struct QueueStack<T> {
  private var leftStack: [T] = []
  private var rightStack: [T] = []

  public init() { }
  
  public var isEmpty: Bool {
    return leftStack.isEmpty && rightStack.isEmpty
  }
  
  public var peek: T? {
    return !leftStack.isEmpty ? leftStack.last : rightStack.first
  }
  
  public var count: Int {
    return leftStack.count + rightStack.count
  }
  
  public mutating func enqueue(_ element: T) {
    rightStack.append(element)
  }
  
  public mutating func dequeue() -> T? {
    if leftStack.isEmpty {
      leftStack = rightStack.reversed()
      rightStack.removeAll()
    }
    return leftStack.popLast()
  }
}

func solution(_ numbers: [Int], _ target: Int) -> Int {
  var queue = QueueStack<Int>()
  var answer = 0
  
  queue.enqueue(0)
  
  for number in numbers {
    for _ in 0 ..< queue.count {
      let numberToCalculate = queue.dequeue() ?? 0
      queue.enqueue(numberToCalculate + number)
      queue.enqueue(numberToCalculate - number)
    }
  }
  
  while !queue.isEmpty {
    let num = queue.dequeue() ?? 0
    if num == target { answer += 1 }
  }
  
  return answer

}


print(solution([1, 1, 1, 1, 1], 3))
