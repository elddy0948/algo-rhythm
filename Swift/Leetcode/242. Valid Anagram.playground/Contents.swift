import Foundation


func isAnagram(_ s: String, _ t: String) -> Bool {
    if (s.count != t.count) {
        return false
    }
    for char in s {
        if (!t.contains(char)) {
            return false
        }
    }
    return true
}

print(isAnagram("anagram", "nagaram"))
