import Foundation

class Solution1991 {
  var tree = [String: (String, String)]()
  
  func solve() {
    let readNodeCount = Int(readLine()!)!
    
    for _ in 0 ..< readNodeCount {
      let readNode = readLine()!.split(separator: " ").map({ String($0) })
      let root = readNode[0]
      let left = readNode[1]
      let right = readNode[2]
      
      tree[root] = (left, right)
    }
    
    preorderTraversal(to: "A")
    print("")
    inorderTraversal(to: "A")
    print("")
    postorderTraversal(to: "A")
  }
  
  func inorderTraversal(to node: String) {
    let currentNode = tree[node] ?? (".", ".")
    
    if currentNode.0 != "." { inorderTraversal(to: currentNode.0) }
    print(node, terminator: "")
    if currentNode.1 != "." { inorderTraversal(to: currentNode.1) }
  }
  
  func preorderTraversal(to node: String) {
    let currentNode = tree[node] ?? (".", ".")
    
    print(node, terminator: "")
    if currentNode.0 != "." { preorderTraversal(to: currentNode.0) }
    if currentNode.1 != "." { preorderTraversal(to: currentNode.1) }
  }
  
  func postorderTraversal(to node: String) {
    let currentNode = tree[node] ?? (".", ".")
    
    if currentNode.0 != "." { postorderTraversal(to: currentNode.0) }
    if currentNode.1 != "." { postorderTraversal(to: currentNode.1) }
    print(node, terminator: "")
  }
}
