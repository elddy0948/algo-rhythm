#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) 
  {
    unordered_map<int, int> numberMap = CreateNumberMap(arr);
    return IsUniqueOccurrences(numberMap);
  }

private:
  unordered_map<int, int> CreateNumberMap(vector<int>& arr)
  {
    unordered_map<int, int> result;
    for (const auto& num : arr) { ++result[num]; }
    return result;
  }

  bool IsUniqueOccurrences(unordered_map<int, int>& numberMap)
  {
    unordered_set<int> numberSet;
    for (const auto& [key, value] : numberMap)
    {
      if (numberSet.count(value)) { return false; }
      numberSet.emplace(value);
    }
    return true;
  }
};


int main(void)
{
  Solution sol;
  vector<int> inp{ 1,2,2,1,1,3 };
  cout << sol.uniqueOccurrences(inp);

  return 0;
}