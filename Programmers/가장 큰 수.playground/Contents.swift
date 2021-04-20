import Foundation


func solution(_ numbers:[Int]) -> String {
    var answer = ""
    let sortedNumbers = numbers.sorted { Int("\($0)\($1)")! > Int("\($1)\($0)")! }
    sortedNumbers.map { answer += "\($0)" }
    if answer.first! == "0" { return "0" }
    return answer
}


print(solution([6, 10, 2]))
