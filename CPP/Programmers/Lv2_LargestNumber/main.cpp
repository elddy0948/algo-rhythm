#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int lhs, int rhs)
{
    string str_lhs = to_string(lhs);
    string str_rhs = to_string(rhs);

    return stoi(str_lhs + str_rhs) > stoi(str_rhs + str_lhs);
}

string solution(vector<int> numbers)
{
    string answer = "";

    sort(numbers.begin(), numbers.end(), compare);

    for (int i = 0; i < numbers.size(); i++)
    {
        answer += to_string(numbers[i]);
    }

    if (answer.front() == '0')
    {
        return "0";
    }

    return answer;
}

int main()
{
    cout << solution({3, 30, 34, 5, 9});
    return 0;
}