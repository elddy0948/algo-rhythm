import Cocoa

func isValid(_ s: String) -> Bool {
    var answer: Bool = true
    var stack:[String] = []
    
    for c in s {
        switch c {
        case "(":
            stack.append(String(c))
        case "[":
            stack.append(String(c))
        case "{":
            stack.append(String(c))
        case ")":
            if stack.last == "(" {
                //true
                answer = true
                stack.popLast()
            } else {
                return false
            }
        case "]":
            if stack.last == "[" {
                //true
                answer = true
                stack.popLast()
            } else {
                return false
            }
        case "}":
            if stack.last == "{" {
                //true
                answer = true
                stack.popLast()
            } else {
                return false
            }
        default:
            return answer
        }
    }
    if stack.count > 0 { return false }
    return answer
}


print(isValid("()("))
