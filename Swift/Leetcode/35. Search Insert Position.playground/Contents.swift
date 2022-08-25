import Foundation

//Given a sorted array of distinct integers and a target value,
//return the index if the target is found.
//If not, return the index where it would be if it were inserted in order.

func searchInsert(_ nums: [Int], _ target: Int) -> Int {
    var low = 0
    var high = nums.count - 1
    
    while low <= high {
        let mid = (low + high) / 2
        if nums[mid] == target {
            return mid
        } else if nums[mid] > target {
            high = mid - 1
        } else if nums[mid] < target {
            low = mid + 1
        }
    }
    return low
}

print(searchInsert([1,3,5,7], 5))
