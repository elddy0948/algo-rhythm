import Foundation

let arr = readLine()!.split(separator: " ").map {Int($0)!}
let numbers = ["zero","one","two","three","four","five","six","seven","eight","nine"]
var ans = [(Int, String)]()
for i in arr[0]...arr[1] {
    var s = ""
    var num = i
    while num > 0 {
        s = "\(numbers[num % 10])\(s)"
        num /= 10
    }
    ans.append((i,s))
}
ans.sort { $0.1 < $1.1 }
var cnt = 0
var oneLine = ""
for i in ans.indices {
    oneLine += "\(ans[i].0)"
    cnt += 1
    if cnt == 10 {
        print(oneLine)
        oneLine = ""
        cnt = 0
    } else {
        oneLine += " "
    }
}
print(oneLine)
