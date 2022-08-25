import Foundation

func cuttingTree(_ a: [Int], key: Int) -> Bool {
    var height: Int = 0
    for tree in a {
        if (tree - key) > 0 {
            height += (tree - key)
        }
    }
    if K <= height {
        return true
    } else {
        return false
    }
}

let read = readLine()?.components(separatedBy: " ")

let N = Int((read?[0])!)!, K = Int((read?[1])!)!
let readTrees = readLine()?.components(separatedBy: " ") ?? [""]

var trees: [Int] = Array<Int>()

for tree in readTrees {
    trees.append(Int(tree)!)
}
trees.sort()
let maxN: Int = trees.last ?? 0
var answer: Int = 0
var range: Range<Int> = 0 ..< maxN

while range.lowerBound <= range.upperBound {
    let midIndex = range.lowerBound + (range.upperBound - range.lowerBound) / 2
    if cuttingTree(trees, key: midIndex) {
        answer = max(answer, midIndex)
        range = midIndex + 1 ..< range.upperBound
    } else {
        if range.lowerBound >= midIndex - 1 { break }
        range = range.lowerBound ..< midIndex - 1
    }
}
print(answer)
