import Foundation

func solution(_ n:Int) -> Int
{
    var answer:Int = 0
    var num = n
    
    while num != 0 {
        answer += num % 10
        num /= 10
    }

    return answer
}

//return String(n).reduce(0, {$0+Int(String($1))!});

solution(987)
