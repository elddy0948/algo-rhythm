import Foundation

// my Solution
func solution(_ s:String, _ n:Int) -> String {
    let upper = Array("abcdefghijklmnopqrstuvwxyz".uppercased())
    let lower = Array("abcdefghijklmnopqrstuvwxyz")
    let ss = Array(s)
    var ans = ""
    
    for i in ss{
        if upper.contains(i){
            var indexNum = upper.firstIndex(of: i)! + n
            
            if indexNum > 25{
                indexNum = indexNum - 26
            }
            ans.append(upper[indexNum])
            
        }else if lower.contains(i){
            var indexNum = lower.firstIndex(of: i)! + n
            
            if indexNum > 25{
                indexNum = indexNum - 26
            }
            ans.append(lower[indexNum])
            
        }else{
            ans.append(i)
        }
    }
    return ans
}

//Good Solution

func solution2(_ s:String, _ n:Int) -> String {
    let alphabets = "abcdefghijklmnopqrstuvwxyz".map { $0 }
    return String(s.map {
        guard let index = alphabets.firstIndex(of: Character($0.lowercased())) else { return $0 }
        let letter = alphabets[(index + n) % alphabets.count]
        return $0.isUppercase ? Character(letter.uppercased()) : letter
    })
}

print(solution("AB", 1))
