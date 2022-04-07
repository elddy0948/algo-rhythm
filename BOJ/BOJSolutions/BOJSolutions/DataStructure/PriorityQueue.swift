import Foundation

struct PriorityQueue<Element: Equatable> {
  private var heap: Heap<Element>
  
  init(sort: @escaping (Element, Element) -> Bool, elements: [Element] = []) {
    heap = Heap(sort: sort, elements: elements)
  }
  
  var isEmpty: Bool {
    return heap.isEmpty
  }
  
  var peek: Element? {
    return heap.peek()
  }
  
  var count: Int {
    return heap.count
  }
  
  @discardableResult
  mutating func enqueue(_ element: Element) -> Bool {
    heap.insert(element)
    return true
  }
  
  mutating func dequeue() -> Element? {
    return heap.remove()
  }
}
