import Foundation

func solution(_ numbers:[Int], _ hand:String) -> String {
    let a = (0, 0)
    var handPath = ""
    var leftHandPos = 10
    var rightHandPos = 12
    
    for num in numbers {
        var number = num
        if number == 0 { number = 11 }
        if number == 1 || number == 4 || number == 7 {
            handPath.append("L")
            leftHandPos = number
        }
        else if number == 3 || number == 6 || number == 9 {
            handPath.append("R")
            rightHandPos = number
        }
        else {
            if abs(leftHandPos - number) < abs(rightHandPos - number) {
                handPath.append("L")
                leftHandPos = number
            }
            else if abs(leftHandPos - number) > abs(rightHandPos - number) {
                handPath.append("R")
                rightHandPos = number
            }
            else if abs(leftHandPos - number) == abs(rightHandPos - number) {
                if hand == "right" {
                    handPath.append("R")
                    rightHandPos = number
                } else {
                    handPath.append("L")
                    leftHandPos = number
                }
            }
            
        }
    }
    return handPath
}

print(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], "right"))
