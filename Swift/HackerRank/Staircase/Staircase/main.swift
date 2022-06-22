import Foundation

/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

func staircase(n: Int) -> Void {
  // Write your code here
  for i in 1 ... n {
    //star count
    var line = ""
    
    for j in 0 ..< n {
      if j >= n - i { line.append("#") }
      else { line.append(" ") }
    }
    
    print(line)
  }
  
}

guard let n = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

staircase(n: n)
