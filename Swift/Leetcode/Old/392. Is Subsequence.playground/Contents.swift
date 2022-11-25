import Foundation


func isSubsequence(_ s: String, _ t: String) -> Bool {
    //Check is Subsequence
    if s.count == 0 {
        return true
    }
    var answer: Bool = false
    var cursor = 0
    let arrS = Array(s)
    for str in t {
        if str == arrS[cursor] {
            cursor += 1
        }
        if cursor == s.count {
            answer = true
            return answer
        }
    }
    return answer
}

print(isSubsequence("abc", "axbxc"))
