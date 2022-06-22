import Foundation

let MAX = 9876543210
let read = Int(readLine() ?? "") ?? 0
var q = [Int](0...9)
var cnt = 10    // 0 ~ 9
if read < 10 {print(read)}

while !q.isEmpty {
    let removedNum = q.removeFirst()
    let num = removedNum % 10
    for i in 0..<num  {
        //다음 숫자는 무조건 감소하는 수로 만들어진다.
        let nextNum = removedNum * 10 + i
        cnt += 1
        if nextNum == MAX && cnt < read + 1 { print(-1); exit(0) }
        if cnt == read + 1 { print(nextNum); exit(0) }
        q.append(nextNum)
    }
}
