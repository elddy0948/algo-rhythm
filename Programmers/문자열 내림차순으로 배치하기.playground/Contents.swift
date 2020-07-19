import Foundation

func solution(_ s:String) -> String {
    let reversedString = String(s.sorted {$0 > $1})
    return reversedString
}

print(solution("Zbcdefg"))
