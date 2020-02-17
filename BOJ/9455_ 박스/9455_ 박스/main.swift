//
//  main.swift
//  9455_ 박스
//
//  Created by 김호준 on 2020/02/17.
//  Copyright © 2020 김호준. All rights reserved.
//

import Foundation

struct Queue<T> {
    var items: [T] = []
    mutating func enqueue(element: T) {
        items.append(element)
    }
    mutating func dequeue() -> T? {
        if items.isEmpty {
            return nil
        }
        else {
            let firstElement: T? = items.first
            items.remove(at: 0)
            return firstElement
        }
    }
    mutating func empty() -> Bool {
        if items.isEmpty {
            return true
        }
        else {
            return false
        }
    }
}

func solution(box: [[Int]], i: Int, j: Int) -> Int {
    var answer: Int = 0
    for line in 0..<j {
        var q: Queue<Int> = Queue<Int>()
        for findZero in (0..<i).reversed() {
            if box[findZero][line] == 0 {
                q.enqueue(element: findZero)
            }
            else {
                if q.empty() {
                    continue
                } else {
                    answer += q.dequeue()! - findZero
                    q.enqueue(element: findZero)
                }
            }
        }
    }
    return answer
}

let test_case = Int(readLine() ?? "") ?? 0

for _ in 0..<test_case {
    let iandj = readLine()?.components(separatedBy: " ")
    let i = Int(iandj![0]) ?? 0
    let j = Int(iandj![1]) ?? 0
    var box_arr: [[Int]] = Array(repeating: Array(repeating: 0, count: j), count: i)
    for a in 0..<i {
        let read = readLine()?.components(separatedBy: " ")
        for b in 0..<j {
            box_arr[a][b] = Int(read![b]) ?? 0
        }
    }
    let ans: Int = solution(box: box_arr, i: i, j: j)
    print(ans)
}
