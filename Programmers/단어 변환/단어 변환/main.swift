import Foundation

struct Node {
  var word: String
  var level: Int
}

func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
  guard words.contains(target) else { return 0 }
  
  var queue = QueueStack<Node>()
  var visited = [Bool](repeating: false, count: words.count)
  
  queue.enqueue(Node(word: begin, level: 0))
  
  while !queue.isEmpty {
    guard let first = queue.dequeue() else { return 0 }
    let level = first.level + 1
    
    for i in 0..<words.count {
      if visited[i] { continue }
      
      let word = words[i]
      
      if checkDifference(first.word, word) {
        if word == target { return level }
        queue.enqueue(Node(word: word, level: level))
        visited[i] = true
      }
    }
  }

  return 0
}

func checkDifference(_ lhs: String, _ rhs: String) -> Bool {
  let first = Array(lhs)
  let second = Array(rhs)
  var difference = 0
  
  for (index, letter) in first.enumerated() {
    if second[index] != letter {
      difference += 1
    }
    
    if difference > 1 {
      return false
    }
  }
  
  return true
}

print(solution("hit", "cog", ["log", "lot", "dog", "dot","cog", "hot"]))

public struct QueueStack<T> {
  private var leftStack = [T]()
  private var rightStack = [T]()
  
  public var isEmpty: Bool {
    return leftStack.isEmpty && rightStack.isEmpty
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
