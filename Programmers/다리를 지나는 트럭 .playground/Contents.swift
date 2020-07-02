import Foundation

func solution(_ bridge_length:Int, _ weight:Int, _ truck_weights:[Int]) -> Int {
    var now_weight = 0
    var now_time = 0
    var trucks = truck_weights
    var q = [(Int,Int)]() // 0 : weights , 1 : times
    
    while !trucks.isEmpty {
        now_time += 1
        if !q.isEmpty {
            if now_time == q.first!.1 {
                now_weight -= q.first!.0
                q.removeFirst()
            }
        }
        if now_weight + trucks.first! <= weight {
            now_weight += trucks.first!
            q.append((trucks.first!, now_time + bridge_length))
            trucks.removeFirst()
        }
        
    }
    return q.last?.1 ?? 0
}

print(solution(5, 5, [1, 1, 1, 1, 1, 2, 2, 2, 2]))
