
import Foundation

func solution(_ n:Int, _ lost:[Int], _ reserve:[Int]) -> Int {
    let losted = lost.filter{!reserve.contains($0)}
    var reserved = reserve.filter{!lost.contains($0)}
    var ans = n - losted.count
    for i in 0..<losted.count {
        var has: Int?
        for j in 0..<reserved.count {
            if losted[i] == reserved[j] - 1 || losted[i] == reserved[j] + 1 {
                has = j
                break
            }
        }
        if let index = has {
            reserved.remove(at: index)
            ans += 1
        }
    }
    return ans
}


print(solution(5, [2,3,4], [1,3,5]))
