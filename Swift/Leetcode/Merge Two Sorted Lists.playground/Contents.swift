import Foundation


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
class Solution {
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        let dum = ListNode(0)
        var node = dum
        
        var listOne = l1
        var listTwo = l2
        
        while listOne != nil && listTwo != nil {
            if listOne!.val < listTwo!.val {
                node.next = listOne
                listOne = listOne!.next
            } else {
                node.next = listTwo
                listTwo = listTwo!.next
            }
            node = node.next!
        }
        node.next = listOne ?? listTwo
        return dum.next
    }
}
