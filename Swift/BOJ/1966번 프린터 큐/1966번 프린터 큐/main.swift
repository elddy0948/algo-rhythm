//
//  main.swift
//  1966번 프린터 큐
//
//  Created by 김호준 on 2020/11/07.
//

import Foundation

let testCase = Int(readLine()!)!

for _ in 0..<testCase {
    var counter = 0
    let readNAndTarget = (readLine()?.components(separatedBy: " "))!
    let n = Int(readNAndTarget[0])!
    let target = Int(readNAndTarget[1])!
    
    let readQueue = (readLine()?.components(separatedBy: " "))!
    var queue = [Int]()
    
    for item in readQueue {
        queue.append(Int(item)!)
    }
    
    let targetPriority = queue[target]
    queue[target] = -1
    
    while true {
        if n == 1 {
            counter += 1
            break
        }
        if queue.first == -1 {
            //it's target
            if queue.max()! <= targetPriority {
                counter += 1
                break
            }
            let temp = queue.removeFirst()
            queue.append(temp)
        } else if queue.first == queue.max() && queue.first! >= targetPriority {
            queue.removeFirst()
            counter += 1
        } else {
            let temp = queue.removeFirst()
            queue.append(temp)
        }
    }
    print(counter)
}
