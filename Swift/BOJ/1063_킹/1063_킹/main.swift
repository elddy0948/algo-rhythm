//
//  main.swift
//  1063_킹
//
//  Created by 김호준 on 2020/04/07.
//  Copyright © 2020 김호준. All rights reserved.
//

import Foundation

typealias makePair = (Int, Int)
let maxLen = 7
let dic: [String : makePair] = ["R":(0,1), "L":(0,-1), "B":(-1,0), "T":(1,0), "RT":(1,1), "LT":(1,-1), "RB":(-1,1), "LB":(-1,-1)]

var kingPos = (0,0), stonePos = (0,0)
var nextKingPos = (0,0), nextStonePos = (0,0)

func moveKing(_ dir: makePair) {
    nextKingPos = (kingPos.0 + dir.0, kingPos.1 + dir.1)
    if nextKingPos.0 < 0 || nextKingPos.1 < 0 || nextKingPos.0 > maxLen || nextKingPos.1 > maxLen {
        return
    }
    if nextKingPos == stonePos {
        nextStonePos = (stonePos.0 + dir.0, stonePos.1 + dir.1)
    }else {
        kingPos = nextKingPos
        return
    }
    if nextStonePos.0 < 0 || nextStonePos.1 < 0 || nextStonePos.0 > maxLen || nextStonePos.1 > maxLen {
        return
    }
    kingPos = nextKingPos
    stonePos = nextStonePos
}

let read = readLine()?.components(separatedBy: " ")

kingPos.1 = Int(((read?[0].first)?.asciiValue)!) - 65
kingPos.0 = Int(((read?[0].last)?.wholeNumberValue)!) - 1

stonePos.1 = Int(((read?[1].first)?.asciiValue)!) - 65
stonePos.0 = Int(((read?[1].last)?.wholeNumberValue)!) - 1

let tc = Int(String(read![2]))!

for _ in 0..<tc {
    let move = dic[readLine()!]!
    moveKing(move)
}

print("\(String(format: "%c", kingPos.1 + 65))\(kingPos.0 + 1)")
print("\(String(format: "%c", stonePos.1 + 65))\(stonePos.0 + 1)")
