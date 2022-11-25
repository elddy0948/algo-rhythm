import Foundation

func strStr(_ haystack: String, _ needle: String) -> Int {
    
    if needle.count == 0 {
        return 0
    } else if needle.count < haystack.count {
        for i in 0..<(haystack.count - needle.count + 1) {
            
            let n1 = haystack.index(haystack.startIndex, offsetBy: i)
            let n2 = haystack.index(haystack.startIndex, offsetBy: i + needle.count)
            let cStr = haystack[n1..<n2]
            
            if cStr == needle {
                return i
            }
        }
    } else if needle.count == haystack.count {
        if needle == haystack {
            return 0
        }
    }
    
    return -1
}
