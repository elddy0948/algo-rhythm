//
//  Connect lands.swift
//  ProgrammersSolutions
//
//  Created by 김호준 on 2022/05/23.
//

import Foundation

final class ConnectIslands {
  var set = [Int](repeating: 0, count: 101)
  
  func getParentIsland(island: Int) -> Int {
    if set[island] == island { return island }
    set[island] = getParentIsland(island: set[island])
    return set[island]
  }
  
  func solution(_ n:Int, _ costs:[[Int]]) -> Int {
    var answer = 0
    
    for i in 0 ..< n {
      set[i] = i
    }
    
    let sortedCosts = costs.sorted(by: { $0[2] < $1[2] })
    
    for i in 0 ..< costs.count {
      let start = getParentIsland(island: sortedCosts[i][0])
      let end = getParentIsland(island: sortedCosts[i][1])
      let cost = sortedCosts[i][2]
      
      if start != end {
        answer += cost
        set[end] = start
      }
    }
    
    return answer
  }
}
