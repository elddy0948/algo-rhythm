import Foundation

func longestCommonPrefix(_ strs: [String]) -> String {
    if strs.isEmpty { return "" }
    
    var res: [[Character]] = []
    var minLen = Int.max
    
    for str in strs {
        let str = Array(str)
        minLen = min(minLen, str.count)
        if !res.isEmpty {
            for i in 0..<minLen {
                if !res.isEmpty && res.first![i] != str[i] {
                    minLen = i
                    break
                }
            }
        }
        if minLen == 0 { return "" }
        res.append(str)
    }
    return String(res[0][0..<minLen])
}


print(longestCommonPrefix(["a","",""]))
