//
//  main.swift
//  11403_경로 찾기
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

func solution (arr: [[Int]], numberOfVertex: Int) -> [[Int]] {
    var answer: [[Int]] = Array(repeating: Array(repeating: 0, count: numberOfVertex), count: numberOfVertex)
    for i in 0..<numberOfVertex {
        var q: Queue<Int> = Queue<Int>()
        var visited: [Int] = Array(repeating: 0, count: numberOfVertex)
        q.enqueue(element: i)
        while !q.empty() {
            let from: Int = q.dequeue()!
            for j in 0..<numberOfVertex {
                if arr[from][j] == 1 && visited[j] == 0 {
                    q.enqueue(element: j)
                    visited[j] = 1
                    answer[i][j] = 1
                }
            }
        }
    }
    return answer
}

let vertex_num = Int(readLine() ?? "") ?? 0

var arr1: [[Int]] = Array(repeating: (Array(repeating: 0, count: vertex_num)), count: vertex_num)

for i in 0..<vertex_num {
    let item = readLine() ?? ""
    let v = item.components(separatedBy: " ")
    for j in 0..<vertex_num {
        arr1[i][j] = Int(v[j]) ?? 0
    }
}

let ans: [[Int]] = solution(arr: arr1, numberOfVertex: vertex_num)
for i in 0..<vertex_num {
    for j in 0..<vertex_num {
        print(ans[i][j] ,terminator: " ")
    }
    print()
}
