import Foundation

let read = readLine() ?? ""
var pipe = [Character]()
var answer = 0
var endPipe = false

for pi in read {
    if pi == "(" {
        pipe.append(pi)
        endPipe = false
    }
    else if pi == ")" {
        if endPipe {
            endPipe = true
            answer += 1
            let _ = pipe.popLast()
        }else {
            endPipe = true
            let _ = pipe.popLast()
            answer += pipe.count
        }
    }
//    print(pipe.count)
}
print(answer)
