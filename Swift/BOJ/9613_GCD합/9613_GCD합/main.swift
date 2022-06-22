import Foundation

func getGCD(_ A: Int, _ B: Int) -> Int{
    if B==0 {
        return A
    }
    return getGCD(B, A%B)
}

let tc = Int(readLine() ?? "") ?? 0

for _ in 0..<tc {
    let arr = readLine()!.split(separator: " ").map { Int($0)! }
    var answer = 0
    for i in 1..<arr.count - 1 {
        for j in i+1..<arr.count {
            let gcd = getGCD(arr[i], arr[j])
            answer += gcd
        }
    }
    print(answer)
}
