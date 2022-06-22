import Foundation

let read = Int(readLine() ?? "") ?? 0
var nums = (1...read).filter {$0 % 2 == 0}
if read % 2 == 1 {
    nums.append(nums.removeFirst())
}
while nums.count != 1 {
    let _ = nums.removeFirst()
    nums.append(nums.removeFirst())
}
print(nums.first!)
