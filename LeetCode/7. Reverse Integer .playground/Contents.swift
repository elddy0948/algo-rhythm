import Cocoa

func reverse(_ x: Int) -> Int {
    var answer: Int = 0
    if x > 0 {
        answer = Int(String(String(x).reversed())) ?? 0
    } else if x < 0 {
        let unX = x * (-1)
        let intX = Int(String(String(unX).reversed())) ?? 0
        answer = intX * -1
    }
    
    if answer > Int32.max {
        return 0
    } else if answer < Int32.min {
        return 0
    }
    
    return answer
}

print(reverse(-2147483648))
