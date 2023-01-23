import Foundation

final class JadenCase {
  func solution(_ s:String) -> String {
    let answer = s.components(separatedBy: " ")
      .map({ $0.enumerated().map({ index, value in
        if index != 0 { return value.lowercased() }
        return value.uppercased()
      })})
      .map({ $0.joined() })
      .joined(separator: " ")
    
    return answer
  }
}
