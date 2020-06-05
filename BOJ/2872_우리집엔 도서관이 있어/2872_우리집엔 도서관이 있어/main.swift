import Foundation

let n = Int(readLine() ?? "") ?? 0
var arr: [Int] = [Int]()

for _ in 0..<n {
    let k = Int(readLine() ?? "") ?? 0
    arr.append(k)
}
var p = n

for i in (0..<n).reversed() {
    if arr[i] == p {
        p -= 1
    }
}

print(p)
