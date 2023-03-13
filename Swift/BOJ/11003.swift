import Foundation

// 시간초과..

final class Deque<T> {
    var enqueue: [T]
    var dequeue: [T] = []

    var count: Int {
      return enqueue.count + dequeue.count
    }

    var isEmpty: Bool {
      return enqueue.isEmpty && dequeue.isEmpty
    }

    var first: T? {
      if dequeue.isEmpty {
        return enqueue.first
      }
      return dequeue.last
    }

    var last: T? {
      if enqueue.isEmpty { return dequeue.first }
      return enqueue.last
    }

    init(_ queue: [T]) { enqueue = queue }

    func pushFirst(_ n: T) {
      dequeue.append(n)
    }

    func pushLast(_ n: T) {
      enqueue.append(n)
    }

    func popFirst() {
      if dequeue.isEmpty {
        dequeue = enqueue.reversed()
        enqueue.removeAll()
      }
      _ = dequeue.popLast()
    }

    func popLast() {
      if enqueue.isEmpty {
        dequeue.reverse()
        _ = dequeue.popLast()
        dequeue.reverse()
      } else {
        _ = enqueue.popLast()
      }
    }
    
    func removeAll() {
      enqueue.removeAll()
      dequeue.removeAll()
    }
}

let readNL = readLine()!.split(separator: " ").map({ Int(String($0))! })
let windowSize = readNL[1]
var deque = Deque([(Int, Int)]())
let numbers = readLine()!.split(separator: " ").map({ Int(String($0))! })

for (index, number) in numbers.enumerated() {
  while deque.count != 0 {
    if let last = deque.last,
        last.0 > number {
      deque.popLast()
    }
    else { break }
  }
  
  deque.pushLast((number, index))

  if let first = deque.first,
      first.1 <= index - windowSize {
        deque.popFirst()
  }

  if let first = deque.first {
    print("\(first.0)", terminator: " ")
  }
}
