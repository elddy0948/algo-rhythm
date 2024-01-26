// Level 1 - 실패율

import Foundation

struct Stage {
  var participants: Int
  var failed: Int
  let stageNumber: Int
}

func solution(_ N:Int, _ stages:[Int]) -> [Int] {
  var stageInformation = [Stage]()
  var sortedStages = stages.sorted()
  
  for i in 0 ... N + 1 { stageInformation.append(Stage(participants: 0, failed: 0, stageNumber: i)) }
  
  while !sortedStages.isEmpty {
    let stage = sortedStages.removeLast()
    
    for i in 1 ... stage {
      stageInformation[i].participants += 1
    }
    stageInformation[stage].failed += 1
  }
  
  let answer = stageInformation.filter({ $0.stageNumber != 0 && $0.stageNumber != N + 1 })
    .sorted(by: { lhs, rhs in
      let lhsFailure = Float(lhs.failed) / Float(lhs.participants)
      let rhsFailure = Float(rhs.failed) / Float(rhs.participants)
      if lhsFailure == rhsFailure { return lhs.stageNumber < rhs.stageNumber }
      return lhsFailure > rhsFailure
    })
    .map({ $0.stageNumber })
  
  return answer
}
