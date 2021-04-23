import Foundation

func solution(_ brown:Int, _ yellow:Int) -> [Int] {
    var width = 0
    var height = 0
    var answer: [Int] = [0, 0]
    
    for i in 1...yellow {
        if yellow % i != 0 { continue }
        width = i
        height = yellow / width
        
        if brown == (2 * width + 2 * height + 4) {
            answer[0] = height + 2
            answer[1] = width + 2
            break
        }
    }
    return answer
}

print(solution(24, 24))
