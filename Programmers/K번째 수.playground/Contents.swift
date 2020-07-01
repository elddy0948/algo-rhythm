import Foundation

//func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
//    var answer = [Int]()
//    for command in commands {
//        var arr = [Int]()
//        arr.append(contentsOf: array[(command[0] - 1)...(command[1] - 1)])
//        arr.sort()
//        answer.append(arr[(command[2] - 1)])
//    }
//    return answer
//}

func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    return commands.map( { array[($0[0] - 1)...($0[1] - 1)].sorted()[$0[2] - 1]})
}

print(solution([1, 5, 2, 6, 3, 7, 4], [[2, 5, 3], [4, 4, 1], [1, 7, 3]]))
