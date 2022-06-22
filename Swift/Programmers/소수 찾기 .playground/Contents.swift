import Cocoa

func solution(_ n:Int) -> Int {
    var count = 0
    var arr = [Bool](repeating: false, count: n + 1)
    
    for i in 2...n {
        if arr[i] == false {
            count += 1
            for j in stride(from: i, through: n, by: i) {
                arr[j] = true
            }
        }
    }
    return count
}

print(solution(10000))
