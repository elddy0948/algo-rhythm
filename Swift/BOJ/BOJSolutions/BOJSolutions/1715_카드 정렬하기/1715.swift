import Foundation

final class Solution1715 {
  func solve() {
    let n: Int = Int(readLine()!)!

    var priorityQueue = PriorityQueue<Int>(sort: <)
    var result = 0
    
    for _ in 0 ..< n {
      let card: Int = Int(readLine()!)!
      priorityQueue.enqueue(card)
    }
    
    while !(priorityQueue.count == 1) {
      let lowestCard = priorityQueue.dequeue() ?? 0
      let secondLowestCard = priorityQueue.dequeue() ?? 0

      let card = secondLowestCard + lowestCard
      result += card
      priorityQueue.enqueue(card)
    }
    print(result)
  }
}
