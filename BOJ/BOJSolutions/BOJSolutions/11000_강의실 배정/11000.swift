import Foundation

final class Solution11000 {
  func solve() {
    var priorityQueue = PriorityQueue<Int>.init(sort: <)
    var timeLine = [(Int, Int)]()
    
    let readN = Int(readLine()!)!
    
    for _ in 0 ..< readN {
      let readTimeLine = readLine()!.split(separator: " ").map({ Int(String($0))! })
      timeLine.append((readTimeLine[0], readTimeLine[1]))
    }
    
    timeLine = timeLine.sorted(by: { $0.0 < $1.0 })
    
    for time in timeLine {
      priorityQueue.enqueue(time.1)
      
      if priorityQueue.count == 1 { continue }
      
      if let peek = priorityQueue.peek {
        if time.0 >= peek { priorityQueue.dequeue() }
      }
    }
    
    print(priorityQueue.count)
  }
}
