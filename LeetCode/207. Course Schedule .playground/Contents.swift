//207. Course Schedule
import Foundation

struct Course {
    let courseNumber: Int
    var courses: [Int]
}

class Solution {
    func canFinish(_ numCourses: Int, _ prerequisites: [[Int]]) -> Bool {
        var courses = createCourses(numCourses)
        var indegree = Array(repeating: 0, count: numCourses)
        var count = 0
        var queue = [Int]()
        
        for course in prerequisites {
            indegree[course[0]] += 1
            courses[course[1]].courses.append(course[0])
        }
        
        for (index, num) in indegree.enumerated() {
            if num == 0 {
                queue.append(index)
            }
        }
        
        while !queue.isEmpty {
            let courseNumber = queue.removeFirst()
            count += 1
            let course = courses[courseNumber]
            for courseNum in course.courses {
                indegree[courseNum] -= 1
                if indegree[courseNum] == 0 {
                    queue.append(courseNum)
                }
            }
        }
        
        return count == numCourses
    }
    
    func createCourses(_ numCourses: Int) -> [Course] {
        var courses = [Course]()
        for courseNumber in 0 ..< numCourses {
            courses.append(Course(courseNumber: courseNumber, courses: []))
        }
        return courses
    }
}


let solution = Solution()
print(solution.canFinish(2, [[1,0],[0,1]]))
