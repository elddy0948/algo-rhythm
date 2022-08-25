import Foundation

let readN = Int(readLine()!)!

for i in 0 ..< readN {
    for j in 0 ..< readN {
        star(i, j, readN)
    }
    print("");
}

func star(_ i: Int, _ j: Int, _ n: Int) {
    if (i / n) % 3 == 1 && (j / n) % 3 == 1 {
        print(" ", terminator: "")
    }
    else {
        if n / 3 == 0 { print("*", terminator: "") }
        else { star(i, j, n / 3) }
    }
}