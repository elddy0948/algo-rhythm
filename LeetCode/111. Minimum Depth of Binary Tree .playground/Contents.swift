import UIKit

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
    var minDepth = Int.max
    var queue = [TreeNode]()
    
    func minDepth(_ root: TreeNode?) -> Int {
        guard let root = root else { return 0 }
        dfs(root, depth: 0)
        return minDepth
    }
    
    private func dfs(_ root: TreeNode?, depth: Int) {
        guard let root = root else { return }
        var depth = depth
        depth += 1
        
        if !isNodeExist(root.left) && !isNodeExist(root.right) {
            minDepth = min(depth, minDepth)
        }
        
        dfs(root.left, depth: depth)
        dfs(root.right, depth: depth)
    }
    
    private func isNodeExist(_ node: TreeNode?) -> Bool {
        return node != nil
    }
}

