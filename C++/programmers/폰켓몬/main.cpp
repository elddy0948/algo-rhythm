#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
  auto answer = 0;
  unordered_map<int, int> dict;

  for (const auto n : nums)
  {
    dict[n]++;
  }

  if (dict.size() > nums.size() / 2)
  {
    answer = nums.size() / 2;
  }
  else
  {
    answer = dict.size();
  }
  return answer;
}