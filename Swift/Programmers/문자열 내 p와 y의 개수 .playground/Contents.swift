import Foundation

//- My Solution
func solution(_ s:String) -> Bool
{
    var pAndy = 0
    s.map{ if $0 == "p" || $0 == "P" {
        pAndy += 1
    } else if $0 == "y" || $0 == "Y" {
        pAndy -= 1
        }
    }
    if pAndy == 0 {
        return true
    }

    return false
}

//- Good Solution


func solution2(_ s:String) -> Bool
{
    return s.lowercased().filter { $0 == "p" }.count == s.lowercased().filter { $0 == "y" }.count
}

print(solution("Pyy"))
