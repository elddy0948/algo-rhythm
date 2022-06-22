import Foundation

// - My Solution
func solution(_ arr:[Int], _ divisor:Int) -> [Int] {
    let answer = arr.filter{ $0 % divisor == 0 }
    if answer.count == 0 { return [-1] }
    return answer.sorted()
}

func solution2(_ arr:[Int], _ divisor:Int) -> [Int] {
    let array = arr.sorted().filter{ $0 % divisor == 0 }
    return  array == [] ? [-1] : array
}

print(solution([2, 36, 1, 3], 1))
