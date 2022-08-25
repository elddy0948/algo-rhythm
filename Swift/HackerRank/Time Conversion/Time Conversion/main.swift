import Foundation

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

func timeConversion(s: String) -> String {
  let hourMinutesSecondsDay = s.components(separatedBy: ":")
  let hour = hourMinutesSecondsDay[0]
  let minutes = hourMinutesSecondsDay[1]
  let seconds = String(hourMinutesSecondsDay[2].prefix(2))
  let day = String(hourMinutesSecondsDay[2].suffix(2))
  
  if day == "AM" {
    if hour == "12" {
      return ["00", minutes, seconds].joined(separator: ":")
    }
    return [hour, minutes, seconds].joined(separator: ":")
  } else if day == "PM" && Int(hour)! < 12 {
    return [String(Int(hour)! + 12), minutes, seconds].joined(separator: ":")
  }
  
  return [hour, minutes, seconds].joined(separator: ":")
}


guard let s = readLine() else { fatalError("Bad input") }

let result = timeConversion(s: s)

print(result)
