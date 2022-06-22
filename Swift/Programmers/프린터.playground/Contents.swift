import Foundation


//중요도 = 1~9

func solution(_ priorities:[Int], _ location:Int) -> Int {
    var prioritiesTuple: [(Int, Int)] = []
    for i in 0..<priorities.count {
        prioritiesTuple.append((priorities[i], i))
    }
    var counter: Int = 0
    
    //remove first and insert last
    var max = maxPriority(in: prioritiesTuple)
    
    while !prioritiesTuple.isEmpty {
        let firstElement = prioritiesTuple.removeFirst()
        
        if firstElement.0 < max {
            prioritiesTuple.append(firstElement)
        } else if firstElement.0 == max {
            counter += 1
            if firstElement.1 == location {
                return counter
            }
        }
        
        if max != maxPriority(in: prioritiesTuple) {
            max = maxPriority(in: prioritiesTuple)
        }
    }
    return counter
}

func maxPriority(in tuple: [(Int, Int)]) -> Int {
    let maxTuple = tuple.max { $0.0 < $1.0 } ?? (9, 100)
    return maxTuple.0
}

print(solution([1, 1, 9, 1, 1, 1], 0))
