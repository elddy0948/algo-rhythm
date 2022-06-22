import Foundation

func solution(_ numbers: String) -> Int {
  let array = Array(numbers).map({ String($0) })
  let set = Set(permutation(array))
  
  return set
    .filter({ checkIsPrime($0) })
    .compactMap({ Int($0) })
    .count
}

func permutation(_ array: [String]) -> Set<String> {
  if array.isEmpty { return [] }
  
  let answerArray = (0 ..< array.count).flatMap({ index -> [String] in
    var removedArray = array
    let element = removedArray.remove(at: index)
    let lhs = [element]
    let rhs = permutation(removedArray).map({ element + $0 })
    
    return lhs + rhs
  })
  
  return Set(answerArray)
}

func checkIsPrime(_ number: String) -> Bool {
  let intNumber = Int(number) ?? 0
  
  guard intNumber >= 2 else { return false }
  guard intNumber != 2 else { return true }
  let max = Int(ceil(sqrt(Double(intNumber))))
  
  for i in 2 ... max {
    if intNumber % i == 0 { return false }
  }
  
  return true
}

print(solution("17"))

public struct QueueStack<T> {
  private var leftStack = [T]()
  private var rightStack = [T]()
  
  public init() { }
  
  public var isEmpty: Bool {
    return leftStack.isEmpty && rightStack.isEmpty
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
