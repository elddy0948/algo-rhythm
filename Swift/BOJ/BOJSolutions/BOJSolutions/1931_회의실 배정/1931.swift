import Foundation

class Solution1931 {
  func solve() {
    let meetingRoomCount = Int(readLine()!)!
    var meetingInformation = [(Int, Int)]()
    var availableMeetings = 0
    var meeting = (-1, -1)
    
    for _ in 0 ..< meetingRoomCount {
      let readMeetingInformation = readLine()!.split(separator: " ").map({ Int($0)! })
      let startTime = readMeetingInformation[0]
      let endTime = readMeetingInformation[1]
      meetingInformation.append((startTime, endTime))
    }
    
    meetingInformation.sort(by: {
      if $0.1 == $1.1 { return $0.0 < $1.0 }
      else { return $0.1 < $1.1 }
    })
    
    for meetingInfo in meetingInformation {
      if meetingInfo.0 >= meeting.1 {
        //can use meetingroom
        meeting = meetingInfo
        availableMeetings += 1
      }
    }
    
    print(availableMeetings)
  }
}
