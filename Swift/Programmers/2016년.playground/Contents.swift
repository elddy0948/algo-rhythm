import Foundation

//func solution(_ a:Int, _ b:Int) -> String {
//    let days = ["THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"]
//    let cal = [(0,0), (1,31), (2,29), (3,31), (4,30), (5,31), (6,30), (7,31), (8,31), (9,30), (10,31), (11,30), (12,31)]
//    var day = 0
//    for i in 1..<a {day += cal[i].1}
//    day += b
//    return days[day % 7]
//}

func solution(_ a:Int, _ b:Int) -> String {
    let days = ["THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"]
    let monthDay = [ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    let totalDay = monthDay[0..<a-1].reduce(0, +) + b
    
    return days[totalDay % 7]
}

print(solution(5, 24))
