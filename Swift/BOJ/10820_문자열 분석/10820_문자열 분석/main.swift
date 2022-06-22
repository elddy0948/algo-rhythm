import Foundation

while let read = readLine() {
    var checkList: [Int] = [0,0,0,0]
    //소문자 대문자 숫자 공백
    
    for ch in read {
        if ch >= "a" && ch <= "z" {
            checkList[0] += 1
        } else if ch == " " {
            checkList[3] += 1
        } else if ch >= "A" && ch <= "Z" {
            checkList[1] += 1
        } else if ch >= "0" && ch <= "9" {
            checkList[2] += 1
        }
    }
    print("\(checkList[0]) \(checkList[1]) \(checkList[2]) \(checkList[3])")
}
