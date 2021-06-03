import Foundation

func solution(_ numbers:[Int], _ target:Int) -> Int {
    var array: [Int] = numbers
    var queue: [Int] = []
    var answer = 0
    
    queue.append(0)
    
    while !array.isEmpty {
        let number = array.removeFirst()
        var tempQueue = [Int]()
        
        for i in 0..<queue.count {
            tempQueue.append(queue[i] + number)
            tempQueue.append(queue[i] - number)
            
            if array.isEmpty && (queue[i] + number == target || queue[i] - number == target) {
                answer += 1
            }
        }
        queue = tempQueue
    }
    return answer
}

print(solution([1, 1, 1, 1, 1], 1))
