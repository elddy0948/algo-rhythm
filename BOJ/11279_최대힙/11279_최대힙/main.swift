import Foundation

extension Array where Element == Int {
    mutating func binarySearchInsert(_ val: Int) {
        if self.isEmpty {
            self.append(val)
            return
        }
        var left = 0
        var right = self.count - 1
        while left <= right {
            let mid = (left + right) / 2
            if self[mid] > val {
                right = mid - 1
            } else {
                left = mid + 1
            }
        }
        self.insert(val, at: left)
    }
}

var queue = [Int]()

guard let operatorCount = Int(readLine() ?? "") else {
    fatalError("Can't get operator count")
}

for _ in 0..<operatorCount {
    guard let operatorNumber = Int(readLine() ?? "") else {
        fatalError("Can't get operator Number")
    }
    if operatorNumber == 0 {
        if queue.isEmpty {
            print(0)
        } else {
            print(queue.removeLast())
        }
    } else {
        queue.binarySearchInsert(operatorNumber)
    }
}


