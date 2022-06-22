import Foundation

typealias Nickname = String
typealias UserID = String

enum State: String {
    case entered = "들어왔습니다."
    case leaved = "나갔습니다."
    case changed
}

struct Log {
    var userID: UserID
    var state: State
}
var userTable = [UserID: Nickname]()
var logs: [Log] = []

func solution(_ record:[String]) -> [String] {
    var answer: [String] = []
    record.forEach { oneRecord in
        let notice = oneRecord.components(separatedBy: " ")
        let state = notice[0]
        switch state {
        case "Enter":
            registerUser(uid: notice[1], nickname: notice[2])
        case "Leave":
            leaveUser(uid: notice[1])
        case "Change":
            editUser(uid: notice[1], nickname: notice[2])
        default:
            break
        }
    }
    logs.map {
        answer.append("\(userTable[$0.userID]!)님이 \($0.state.rawValue)")
    }
    return answer
}

func registerUser(uid: UserID, nickname: Nickname) {
    userTable[uid] = nickname
    let log = Log(userID: uid, state: .entered)
    logs.append(log)
}

func leaveUser(uid: String) {
    let log = Log(userID: uid, state: .leaved)
    logs.append(log)
}

func editUser(uid: String, nickname: String) {
    userTable[uid] = nickname
}


print(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]))
