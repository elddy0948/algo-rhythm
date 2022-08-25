#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;

    sort(citations.begin(), citations.end(), greater<int>());

    size_t i = 0;
    for (; i != citations.size(); ++i)
    {
        if (i + 1 > citations[i])
        {
            break;
        }
    }
    answer = i;

    return answer;
}

int main()
{
    cout << solution({0, 2});
    return 0;
}