import Foundation

func solution(_ n:Int, _ arr1:[Int], _ arr2:[Int]) -> [String] {
    var answer: [String] = []
    
    for i in 0 ..< n {
        var string = ""
        var string1 = String(arr1[i], radix: 2)
        var string2 = String(arr2[i], radix: 2)
        for _ in 0..<n - string1.count {
            string1 = "0" + string1
        }
        for _ in 0..<n - string2.count {
            string2 = "0" + string2
        }
        for i in 0..<n {
            let a = string1.index(string1.startIndex, offsetBy: i)
            let b = string2.index(string2.startIndex, offsetBy: i)
            if string1[a] == "1" || string2[b] == "1" {
                string += "#"
            } else {
                string += " "
            }
        }
        answer.append(string)
    }
    return answer
}

print(solution(6, [46, 33, 33 ,22, 31, 50], [27 ,56, 19, 14, 14, 10]))
