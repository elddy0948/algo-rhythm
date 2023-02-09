#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int longestWPI(vector<int> &hours)
  {
    int longestInterval = 0;
    int accu = 0;

    unordered_map<int, int> lookup;

    for (int i = 0; i < hours.size(); ++i)
    {
      if (hours[i] > 8)
        accu += 1;
      else
        accu -= 1;

      if (accu > 0)
        longestInterval = i + 1;
      else if (lookup.count(accu - 1))
        longestInterval = max(longestInterval, i - lookup[accu - 1]);

      if (!lookup.count(accu))
        lookup[accu] = i;
    }
    return longestInterval;
  }
};

int main()
{
  Solution sol;

  vector<int> inp = {9, 9, 6, 0, 6, 6, 9};
  int result = sol.longestWPI(inp);

  cout << result << endl;

  return 0;
}