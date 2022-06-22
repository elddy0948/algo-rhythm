import Foundation

guard let numberOfSolution = Int(readLine() ?? "") else {
    fatalError("There is Nothing to read")
}
guard let readSolutions = readLine()?.split(separator: " ") else {
    fatalError("Can't read solutions")
}
let solutions = readSolutions.map { Int($0) ?? 0 }
var maxSolution = Int.max
var answer = (0, 0)

outerLoop: for solution in solutions.indices {
    var left = solution + 1
    var right = numberOfSolution - 1
    
    while left <= right {
        let mid = (left + right) / 2
        let sum = solutions[solution] + solutions[mid]
        var compSum = sum
        compSum *= sum < 0 ? -1 : 1
        
        if maxSolution > compSum {
            maxSolution = compSum
            answer = (solutions[solution], solutions[mid])
        }
        
        if maxSolution == 0 { break outerLoop }
        
        if sum < 0 {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }
}
print("\(answer.0) \(answer.1)")
