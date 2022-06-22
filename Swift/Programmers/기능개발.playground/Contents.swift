import Foundation

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var progressEndDay = [Int]()
    var answer = [Int]()
    
    for progress in 0..<progresses.count {
        let progressDay: Double = Double(100 - progresses[progress]) / Double(speeds[progress])
        progressEndDay.append(Int(ceil(progressDay)))
    }
    while !progressEndDay.isEmpty {
        var progressCounter = 0
        if let firstProgress = progressEndDay.first {
            for progress in 0..<progressEndDay.count {
                if progressEndDay[progress] <= firstProgress {
                    progressCounter += 1
                } else { break }
            }
            answer.append(progressCounter)
            for _ in 0..<progressCounter {
                progressEndDay.removeFirst()
            }
        }
    }
    return answer
}

print(solution([95, 90, 99, 99, 80, 99], [1, 1, 1, 1, 1, 1]))
