import Foundation


//typealias를 사용 한 방법
typealias StringIntDic = [String: Int]
var myDictionary: StringIntDic = ["Swift": 100, "Howift": 300, "Study": 500]
print(myDictionary.count)   //3
if myDictionary.isEmpty {
    print("Dictionary is empty")
}else {
    print("Dictionary is not empty")
}   //Dictionary is not empty
myDictionary["Hello"] = 200 //["Hello": 200, "Howift": 300, "Study": 500, "Swift": 100]
myDictionary.updateValue(1000, forKey: "Howift")    //["Study": 500, "Swift": 100, "Hello": 200, "Howift": 1000]
myDictionary["Hello"] = nil //["Study": 500, "Swift": 100, "Howift": 1000]

for (str, number) in myDictionary {
    print("\(str) : \(number)")
//    Study : 500
//    Swift : 100
//    Howift : 1000
}
for str in myDictionary.keys {
    print(str)
//    Study
//    Swift
//    Howift
}
for num in myDictionary.values {
    print(num)
//    500
//    100
//    1000
}
let keyInDictionary = [String](myDictionary.keys)   //["Study", "Howift", "Swift"]
let valuesInDictionary = [Int](myDictionary.values) //[500, 1000, 100]
