#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
  vector<string> generateParenthesis(int n) 
  {
    length = n;
    BackTracking("(", 1, 0);
    return results;
  }

private:
  void BackTracking(string result, int open, int close)
  {
    if (result.size() == length * 2)
    {
      results.emplace_back(result);
      return;
    }

    if (close < open && close < length)
    {
      BackTracking(result + ')', open, close + 1);
    }
    if (open >= close && open < length)
    {
      BackTracking(result + '(', open + 1, close);
    }

    return;
  }

private:
  int length;
  vector<string> results{};
};

int main(void)
{
  Solution sol;

  for (auto result : sol.generateParenthesis(1))
  {
    cout << result << '\n';
  }

  return 0;
}