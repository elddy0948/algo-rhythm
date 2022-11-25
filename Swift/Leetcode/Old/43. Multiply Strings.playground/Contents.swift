import Foundation

func multiply(_ num1: String, _ num2: String) -> String {
    var sum = [Int](repeating: 0, count: num1.count + num2.count)
    
    for (i, n1) in num1.enumerated().reversed() {
        for (j, n2) in num2.enumerated().reversed() {
            guard let digit1 = Int(String(n1)),
                  let digit2 = Int(String(n2)) else {
                return ""
            }
            let p1 = i + j
            let p2 = i + j + 1
            let val = digit1 * digit2 + sum[p2]
            
            sum[p2] = val % 10
            sum[p1] += val / 10
        }
    }
    
    while let first = sum.first,
          first == 0 {
        sum.removeFirst()
    }
    
    let answer = sum.map { String($0) }.joined()
    return answer.count > 0 ? answer : "0"
}

print(multiply("23", "31"))
