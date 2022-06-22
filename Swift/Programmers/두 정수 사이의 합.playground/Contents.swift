import Foundation

func solution(_ a:Int, _ b:Int) -> Int64 {
    var num1: Int64 = Int64(a)
    var num2: Int64 = Int64(b)
    var answer: Int64 = 0
    if num2 < num1 {
        swap(&num1, &num2)
    }
    for num in num1...num2 {
        answer += num
    }
    return answer
}


print(solution(3, 3))
