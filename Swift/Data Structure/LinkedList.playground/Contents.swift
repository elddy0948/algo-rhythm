import UIKit

public class JoonsNode<T> {
    public var value: T
    public var nextNode: JoonsNode?
    
    public init(value: T, nextNode: JoonsNode? = nil) {
        self.value = value
        self.nextNode = nextNode
    }
}

extension JoonsNode: CustomStringConvertible {
    public var description: String {
        guard let next = nextNode else {
            return "\(value)"
        }
        return "\(value) -> " + String(describing: next) + " "
    }
}

public struct JoonsLinkedList<T> {
    public var head: JoonsNode<T>?
    public var tail: JoonsNode<T>?
    
    public init() {}
    
    public var isEmpty: Bool {
        head == nil
    }

    public mutating func push(_ value: T) {
        head = JoonsNode(value: value, nextNode: head)
        // Linked List에 Node가 한개만 존재했다면
        if tail == nil {
            tail = head
        }
    }
    
    public mutating func append(_ value: T) {
        //비어있는 List이면 append한 값이 head가 되는것과 같다.
        guard !isEmpty else {
            push(value)
            return
        }
        
        //현재 tail의 다음이 append한 node가 된다.
        tail!.nextNode = JoonsNode(value: value)
        
        //그리고 현재 tail 은 방금 추가해 준 Node가 된다.
        tail = tail!.nextNode
    }
    
    public func node(at index: Int) -> JoonsNode<T>? {
        var nowNode = head
        var nowIndex = 0
        
        //찾고자 하는 위치까지 이동
        while nowNode != nil && nowIndex < index {
            nowNode = nowNode?.nextNode
            nowIndex += 1
        }
        
        return nowNode
    }
    
    @discardableResult
    public mutating func insert(_ value: T, after node: JoonsNode<T>) -> JoonsNode<T> {
        guard tail !== node else {
            append(value)
            return tail!
        }
        
        node.nextNode = JoonsNode(value: value, nextNode: node.nextNode)
        return node.nextNode!
    }
    
    //MARK: - Remove Values
    @discardableResult
    public mutating func pop() -> T? {
        defer {
            //2
            head = head?.nextNode
            if isEmpty {
                tail = nil
            }
        }
        //1
        return head?.value
    }
    
    @discardableResult
    public mutating func removeLast() -> T? {
        guard let head = head else {
            return nil
        }
        guard head.nextNode != nil else {
            return pop()
        }
        
        var pre = head
        var current = head
        
        //제일 마지막 노드를 찾아가는 과정
        while let next = current.nextNode {
            pre = current
            current = next
        }
        pre.nextNode = nil
        tail = pre
        return current.value
    }
    
    @discardableResult
    public mutating func remove(after node: JoonsNode<T>) -> T? {
        defer {
            if node.nextNode === tail {
                tail = node
            }
            node.nextNode = node.nextNode?.nextNode
        }
        return node.nextNode?.value
    }
}

extension JoonsLinkedList: CustomStringConvertible {
    public var description: String {
        guard let head = head else {
            return "Empty List"
        }
        return String(describing: head)
    }
}

var list = JoonsLinkedList<Int>()

list.push(3)
list.push(2)
list.push(1)
print(list)

let removeNode = list.node(at: 0)!
list.remove(after: removeNode)
print(list)
