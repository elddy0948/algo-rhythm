import Foundation

/*
 * Complete the 'gridlandMetro' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. INTEGER k
 *  4. 2D_INTEGER_ARRAY track
 */

func gridlandMetro(n: Int, m: Int, k: Int, track: [[Int]]) -> Int {
  var answer = 0
  
  if k < n {
    answer += ((n - k) * m)
  }
  
  for line in track {
    let lampposts = m - (line[2] - line[1] + 1)
    answer += lampposts
  }

  
  return answer
}

//let stdout = ProcessInfo.processInfo.environment["OUTPUT_PATH"]!
//FileManager.default.createFile(atPath: stdout, contents: nil, attributes: nil)
//let fileHandle = FileHandle(forWritingAtPath: stdout)!

guard let firstMultipleInputTemp = readLine()?.replacingOccurrences(of: "\\s+$", with: "", options: .regularExpression) else { fatalError("Bad input") }
let firstMultipleInput = firstMultipleInputTemp.split(separator: " ").map{ String($0) }

guard let n = Int(firstMultipleInput[0])
else { fatalError("Bad input") }

guard let m = Int(firstMultipleInput[1])
else { fatalError("Bad input") }

guard let k = Int(firstMultipleInput[2])
else { fatalError("Bad input") }

var track = [[Int]]()

for _ in 1...k {
    guard let trackRowTemp = readLine()?.replacingOccurrences(of: "\\s+$", with: "", options: .regularExpression) else { fatalError("Bad input") }

    let trackRow: [Int] = trackRowTemp.split(separator: " ").map {
        if let trackItem = Int($0) {
            return trackItem
        } else { fatalError("Bad input") }
    }

    guard trackRow.count == 3 else { fatalError("Bad input") }

    track.append(trackRow)
}

guard track.count == k else { fatalError("Bad input") }

let result = gridlandMetro(n: n, m: m, k: k, track: track)
print(result)

//fileHandle.write(String(result).data(using: .utf8)!)
//fileHandle.write("\n".data(using: .utf8)!)
