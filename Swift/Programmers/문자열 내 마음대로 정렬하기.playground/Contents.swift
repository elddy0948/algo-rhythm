import Foundation

func solution(_ strings:[String], _ n:Int) -> [String] {
    let index = strings[0].index(strings[0].startIndex, offsetBy: n)
    let answer = strings.sorted(by: {(str1: String, str2: String) -> Bool in
        if str1[index] == str2[index] {
            return str1 < str2
        } else {
            return str1[index] < str2[index]
        }
    })
    return answer
}

print(solution(["abce", "abcd", "cdx"], 2))
