import Foundation

// 이름 국 영 수
typealias Student = (String, Int, Int, Int)
var students: [Student] = []

let readN = Int(readLine() ?? "") ?? 0
for _ in 0..<readN {
    let read = readLine()?.components(separatedBy: " ")
    students.append((read?[0], Int(read?[1]), Int(read?[2]), Int(read?[3])))
    students.append(Student.)
}
