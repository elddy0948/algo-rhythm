import Foundation

func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
    var answer: [Int] = []
    
    for i in 0..<nums.count {
        let num = target - nums[i]
        for j in i + 1..<nums.count {
            if nums[j] == num {
                answer.append(i)
                answer.append(j)
                break
            }
        }
        if answer.count != 0 { break }
    }
    return answer
}

print(twoSum([-1,-2,-3,-4,-5], -8))
