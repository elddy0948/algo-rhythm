#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
  string answer = "";
  unordered_map<string, int> completionList;

  for (const auto &people : participant)
  {
    completionList[people] += 1;
  }

  for (const auto &people : completion)
  {
    completionList[people] -= 1;
  }

  for (const auto &info : completionList)
  {
    if (info.second != 0)
    {
      answer = info.first;
    }
  }

  return answer;
}