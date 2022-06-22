import Foundation

func findGCD(_ lhs: Int, _ rhs: Int) -> Int {
    // always rhs > lhs
    let remain = lhs % rhs
    if remain == 0 {
        return rhs
    } else {
        return findGCD(rhs, remain)
    }
}

func solution(_ w:Int, _ h:Int) -> Int64{
    var answer: Int64 = 0
    let gcd: Int
    
    if w >= h {
        gcd = findGCD(h, w)
    } else {
        gcd = findGCD(w, h)
    }
    
    answer = Int64(w * h) - Int64(w + h - gcd)
    return answer
}

solution(8, 12)
