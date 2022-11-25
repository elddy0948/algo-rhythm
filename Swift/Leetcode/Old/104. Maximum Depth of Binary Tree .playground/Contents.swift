
func maxDepth(_ root: TreeNode?) -> Int {
    if root == nil {
        return 0
    }
    else {
        return 1 + max(maxDepth(root!.left), maxDepth(root!.right))
    }
}


let tree = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
maxDepth(tree)
