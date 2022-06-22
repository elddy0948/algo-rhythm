import Foundation

let N = Int(readLine() ?? "") ?? 0

var ans = 0
let M = Int(readLine() ?? "") ?? 0
let arr = Array(readLine()!)
var i = 0


while i < M {
    if i < M-2 && arr[i+1] == "O" && arr[i+2] == "I" {
        var oCnt = 0
        while i < M-2 && arr[i] == "I" && arr[i+1] == "O" && arr[i+2] == "I" {
            oCnt += 1
            i += 2
            if oCnt == N {
                oCnt -= 1
                ans += 1
            }
        }
    }
    i += 1
}

print(ans)
