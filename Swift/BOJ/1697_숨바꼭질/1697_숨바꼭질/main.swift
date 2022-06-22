import Foundation

func solution(_ N: Int, _ X: Int) -> Int {
    var q = [(Int,Int)]()
    var arr = [Int](repeating: 0, count: 100001)
    var answer = 100001
    q.append((N,0))
    while !q.isEmpty {
        let nowPos = q.first!.0
        let nowStep = q.first!.1
        q.removeFirst()
        
        if nowStep >= answer {continue}
        if nowPos > X { answer = min(answer, nowPos - X + nowStep); continue }
        if nowPos * 2 <= 100001 && arr[nowPos * 2] == 0 {
            if nowPos * 2 == X { answer = min(answer, nowStep + 1); break}
            arr[nowPos * 2] = nowStep + 1
            q.append((nowPos * 2, nowStep + 1))
        }
        if nowPos - 1 > 0 && arr[nowPos - 1] == 0 {
            if nowPos - 1 == X { answer = min(answer, nowStep + 1); break}
            arr[nowPos - 1] = nowStep + 1
            q.append((nowPos - 1, nowStep + 1))
        }
        if arr[nowPos + 1] == 0 {
            if nowPos + 1 == X { answer = min(answer, nowStep + 1); break }
            arr[nowPos + 1] = nowStep + 1
            q.append((nowPos + 1, nowStep + 1))
        }
    }
    return answer
}

let read = readLine()?.split(separator: " ").map { Int($0)! }
let N = (read?[0])!; let X = (read?[1])!
var answer = 0
if N >= X {answer = N - X}
else { answer = solution(N, X)}
print(answer)
