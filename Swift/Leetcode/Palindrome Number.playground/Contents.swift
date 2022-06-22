import Cocoa


func isPalindrome(_ x: Int) -> Bool {
    var answer = false
    let strX = String(x)
    let reversedX = String(x).reversed()
    
    if strX == String(reversedX) {
        answer = true
    }
    return answer
}

print(isPalindrome(10))
