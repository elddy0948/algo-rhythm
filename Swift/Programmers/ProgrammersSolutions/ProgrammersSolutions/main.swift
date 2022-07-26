import Foundation

let problem = StringCompression()

print(problem.solution("abcabcabcabcdededededede"))


//func substring(string: String, range: Range<Int>) -> String {
//  let startIndex = string.index(string.startIndex, offsetBy: range.lowerBound)
//  let endIndex = string.index(string.startIndex, offsetBy: range.upperBound)
//  let range = startIndex ..< endIndex
//  return String(string[range])
//}

//print(substring(string: "abcd", range: 0 ..< 1))
//
//for i in stride(from: 0, to: 5, by: 1) {
//  print(i)
//}
