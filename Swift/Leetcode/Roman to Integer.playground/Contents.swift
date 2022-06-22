import Cocoa


//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000

func romanToInt(_ s: String) -> Int {
    let romantoint: [Character: Int] = ["I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000]
    var answer = 0
    var beforeStr: String = ""
    
    for str in s {
        if str == "V" || str == "X" {
            if beforeStr == "I" {
                answer += ((romantoint[str] ?? 0) - 2)
            } else { answer += (romantoint[str] ?? 0) }
        } else if str == "L" || str == "C" {
            if beforeStr == "X" {
                answer += ((romantoint[str] ?? 0) - 20)
            } else { answer += (romantoint[str] ?? 0) }
        } else if str == "D" || str == "M" {
            if beforeStr == "C" {
                answer += ((romantoint[str] ?? 0) - 200)
            } else { answer += (romantoint[str] ?? 0) }
        } else { answer += (romantoint[str] ?? 0) }
        beforeStr = String(str)
    }
    return answer
}

print(romanToInt("LVIII"))
