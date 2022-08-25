import Foundation

func solution(_ answers:[Int]) -> [Int] {
    
    var answerArr = [Int]()
    
    let oneAnswer = [1, 2, 3, 4, 5]
    let twoAnswer = [2, 1, 2, 3, 2, 4, 2, 5]
    let threeAnswer = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    
    var oneCount = 0
    var twoCount = 0
    var thirdCount = 0
    
    answers.enumerated().forEach { (index, element) in
        if element == oneAnswer[index % oneAnswer.count] {
            oneCount += 1
        }
        if element == twoAnswer[index % twoAnswer.count] {
            twoCount += 1
        }
        if element == threeAnswer[index % threeAnswer.count] {
            thirdCount += 1
        }
    }
    
    
    let maxScore = max(oneCount, max(twoCount, thirdCount))
    
    if maxScore == oneCount { answerArr.append(1) }
    if maxScore == twoCount { answerArr.append(2) }
    if maxScore == thirdCount { answerArr.append(3) }
    
    return answerArr
}


solution([1,3,2,4,2])
