import Foundation

let read = Int(readLine() ?? "") ?? 0

if read == 1 { print(1) }
else if read == 2 { print(2) }
else {
    var a = 1
    var b = 2
    var answer = 3
    for _ in 3...read {
        answer = (a + b) % 15746
        a = b
        b = answer
    }
    print(answer % 15746)
}
