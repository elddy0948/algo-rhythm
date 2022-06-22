#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    queue<int> q;

    q.push(numbers[0]);
    q.push(-numbers[0]);

    for (int i = 1; i < numbers.size(); i++)
    {
        int queue_count = q.size();

        for (int j = 0; j < queue_count; j++)
        {
            int number = q.front();
            int plus_number = number + numbers[i];
            int minus_number = number - numbers[i];
            q.pop();

            // cout << plus_number << ' ' << minus_number << '\n';

            if ((i == numbers.size() - 1) && ((plus_number == target) || (minus_number == target)))
            {
                answer += 1;
                continue;
            }

            q.push(plus_number);
            q.push(minus_number);
        }
    }

    return answer;
}

int main()
{
    vector<int> inp{4, 1, 2, 1};
    cout << solution(inp, 4);
}