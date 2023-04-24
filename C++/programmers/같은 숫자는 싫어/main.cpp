#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
  vector<int> answer;

  for (const auto &n : arr)
  {
    if (answer.empty())
    {
      answer.push_back(n);
      continue;
    }
    else if (answer.back() == n)
    {
      continue;
    }
    else
    {
      answer.push_back(n);
    }
  }

  return answer;
}