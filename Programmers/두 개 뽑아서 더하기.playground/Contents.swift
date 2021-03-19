import Foundation

func solution(_ numbers:[Int]) -> [Int] {
    var numberArr = numbers
    var numberSet = Set<Int>()
    var answer = [Int]()
    
    numberArr.map {
        numberArr.removeFirst()
        numberArr.reduce(into: $0) { (x, y) in
            numberSet.insert(x + y)
        }
    }
    answer = Array(numberSet.sorted())

    return answer
}

solution([2,1,3,4,1])
