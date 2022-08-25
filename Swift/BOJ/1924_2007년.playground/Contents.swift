import Foundation


typealias monthDay = (Int, Int)
let months: [monthDay] = [(0,0),(1,31),(2,28),(3,31),(4,30),(5,31),(6,30),(7,31),(8,31),(9,30),(10,31),(11,30),(12,31)]
let c: [String] = ["SUN","MON","TUE","WED","THU","FRI","SAT"]

func solution(_ month: Int, day: Int) -> String {
    var dayCounter: Int = 0
    for i in 0..<month {
        dayCounter += months[i].1
    }
    dayCounter += day
    
    return c[dayCounter % 7]
}
let read = readLine()?.components(separatedBy: " ")
let answer = solution(Int((read?[0])!)!, day: Int((read?[1])!)!)
//let answer = solution(12, day: 25)

print(answer)
