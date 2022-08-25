import Foundation

// - My Solution
func solution(_ s:String) -> Bool {
    let numbers = ["1","2","3","4","5","6","7","8","9","0"]
    if s.count == 4 || s.count == 6 {
        for str in s {
            if numbers.contains(String(str)) {
                continue
            } else {
                return false
            }
        }
    } else {
        return false
    }
    return true
}

// - Good Solution
func solution2(_ s:String) -> Bool {
    return (Int(s) != nil && (s.count == 4 || s.count == 6)) ? true : false
}

print(solution("1234"))
