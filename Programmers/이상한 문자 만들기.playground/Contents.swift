import Foundation

func solution(_ s:String) -> String {
    let str = s.components(separatedBy: " ").map {$0.enumerated().map { $0.offset % 2 == 0 ? $0.element.uppercased() : $0.element.lowercased() } }
    return str.map{ $0.map { $0 }.joined() }.joined(separator: " ")
}

solution("hello world")
