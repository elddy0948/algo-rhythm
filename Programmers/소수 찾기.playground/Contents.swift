import Foundation

var primeNumbers: Set<Int> = []
var maxDepth: Int = 0

struct NumberElement {
    var number: String
    var visited: Bool = false
}

func solution(_ numbers:String) -> Int {
    var numberArray = [NumberElement]()
    numbers.map {
        let numberElement = NumberElement(number: String($0))
        numberArray.append(numberElement)
    }
    
    maxDepth = numberArray.count
    
    for i in 0..<numberArray.count {
        DFS(index: i, numberArray: numberArray, value: "")
    }
    
    return primeNumbers.count
}

func DFS(index: Int, numberArray: [NumberElement], value: String) {
    var temp = numberArray
    var tempValue = value
    temp[index].visited = true
    tempValue = value + temp[index].number
    let intValue = Int(tempValue)!
    if isPrime(intValue) {
        primeNumbers.insert(intValue)
    }
    
    if tempValue.count == numberArray.count { return }
    
    for i in 0..<numberArray.count {
        if temp[i].visited == false {
            DFS(index: i, numberArray: temp, value: tempValue)
        }
    }
}

func isPrime(_ number: Int) -> Bool {
    guard number > 1 else { return false }
    guard number != 2 else { return true }
    
    var isPrime = true
    
    for i in 2...Int((sqrt(Double(number))))+1 {
        if number % i == 0 {
            isPrime = false
            break
        }
    }
    
    return isPrime
}

print(solution("011"))
