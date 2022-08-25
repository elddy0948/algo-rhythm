import Foundation

func solution(_ n:Int, _ lost:[Int], _ reserve:[Int]) -> Int {
    var answer = 0
    var arr = Array<Int>(repeating: 1, count: n + 2)
    for num in lost { arr[num] = 0 }
    for num in reserve { arr[num] += 1 }

    for i in 1..<arr.count {
        if arr[i] == 2 {
            if arr[i - 1] == 0 {
                arr[i] -= 1
                arr[i - 1] += 1
            }
            else if arr[i + 1] == 0 {
                arr[i] -= 1
                arr[i + 1] += 1
            }
            print(i)
        }
    }
    for i in 1..<arr.count - 1 {
        if arr[i] > 0 { answer += 1 }
    }
    return answer
}


print(solution(3, [3], [1]))
