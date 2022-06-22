import Foundation

let N = Int(readLine() ?? "") ?? 0

if N <= 10 { print(N - 1); exit(0) }
var cnt = 11
var Q = [Int](0...9)
while !Q.isEmpty {
    let val = Q.removeFirst()
    let tar = val % 10
    for i in 0..<tar {
        let now = val * 10 + i
        if now == 9876543210 && cnt < N { print(-1); exit(0) }
        if cnt == N {print(now); exit(0) }
        Q.append(now)
        cnt += 1
    }
}
