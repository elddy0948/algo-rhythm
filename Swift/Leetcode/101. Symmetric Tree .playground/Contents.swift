import Foundation


// * Definition for a binary tree node.

public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init() { self.val = 0; self.left = nil; self.right = nil; }
    public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
    public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
        self.val = val
        self.left = left
        self.right = right
    }
}

class Solution {
    func isSymmetric(_ root: TreeNode?) -> Bool {
        guard let root = root else {
            return true
        }
        return bfs(root.left, root.right)
    }
    
    private func bfs(_ leftNode: TreeNode?, _ rightNode: TreeNode?) -> Bool {
        //Node의 자식이 없다.
        if leftNode == nil && rightNode == nil {
            return true
        }
        
        //Node 한쪽에만 자식이 있다. -> 대칭이 아님
        if leftNode == nil || rightNode == nil {
            return false
        }
        
        if leftNode!.val == rightNode!.val &&
            bfs(leftNode!.left, rightNode!.right) &&
            bfs(leftNode!.right, rightNode!.left) {
            return true
        } else {
            return false
        }
    }
}
