import Foundation

// - My Solution
func solution(_ s:String) -> String {
    var str = ""
    if s.count % 2 == 0 {
        let index1 = s.index(s.startIndex, offsetBy: s.count / 2)
        let index2 = s.index(s.startIndex, offsetBy: s.count / 2 - 1)
        str = "\(s[index2])\(s[index1])"
    } else {
        let index1 = s.index(s.startIndex, offsetBy: s.count / 2)
        str = "\(s[index1])"
    }
    return str
}

// - Good Solution
func solution2(_ s:String) -> String {
    if Array(s).count % 2 == 0 {
        return String(Array(s)[(s.count / 2) - 1...(s.count / 2)])
    }else{
        return String(Array(s)[s.count / 2])
    }
}


print(solution("qwer"))
