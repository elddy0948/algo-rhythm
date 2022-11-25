import Foundation

func singleNumber(_ nums: [Int]) -> Int {
    var answer = 0
    
    for n in nums {
        answer ^= n
    }
    
    return answer
}

print(singleNumber([2,2,1]))
