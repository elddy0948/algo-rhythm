import Foundation

class MenuRenewal {
  var combinationDictionary = [String: Int]()
  var course_counts = [Int](repeating: 0, count: 11)
  
  func combination(_ orders: [String], cursor: Int, combinationString: String) {
    if cursor == orders.count {
      if combinationDictionary[combinationString] == nil {
        combinationDictionary[combinationString] = 1
      } else {
        combinationDictionary[combinationString]! += 1
      }
      
      course_counts[combinationString.count] = max(course_counts[combinationString.count], combinationDictionary[combinationString]!)
      
      return
    }
    
    combination(orders, cursor: cursor + 1, combinationString: combinationString + orders[cursor])
    combination(orders, cursor: cursor + 1, combinationString: combinationString)
  }
  
  func solution(_ orders:[String], _ course:[Int]) -> [String] {
    for order in orders {
      let sortedOrder = order.sorted().map({ String($0) })
      combination(sortedOrder, cursor: 0, combinationString: "")
    }
    
    
    let answer = combinationDictionary.filter({ element in
      return (element.value >= 2) && course.contains(element.key.count) && course_counts[element.key.count] == element.value
    }).map({ $0.key })
      .sorted()
    
    return answer
  }
}
