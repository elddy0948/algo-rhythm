import Cocoa

func solution(_ n:Int) -> Int {
    var answer = 0
    let doubleN = Double(n)
    
    if n == 0 { return 0 }
    
    for i in  1...Int(sqrt(doubleN)) {
        if n % i == 0 {
            answer += i
            if i != n / i {
                answer += n / i
            }
        }
    }
    return answer
}

print(solution(0))

// Nice Solution!

//func solution(_ n:Int) -> Int {
//    guard n != 0 else {
//        return 0
//    }
//    return Array(1...n).filter{n % $0 == 0}.reduce(0, +)
//}
