#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<string> result;

public:
  vector<string> permutation(string S)
  {
    string inputString = "";

    backtracking(S, inputString, 0, S.length() - 1);

    for (const auto &c : result)
    {
      cout << c << endl;
    }

    return result;
  }

private:
  void backtracking(string baseString, string newString, int index, int length)
  {
    if (index == length)
    {
      newString += baseString[index];
      result.emplace_back(newString);
      return;
    }

    // space
    backtracking(baseString, newString + baseString[index] + ' ', index + 1, length);
    // no space
    backtracking(baseString, newString + baseString[index], index + 1, length);
    return;
  }
};

int main()
{
  Solution sol = Solution();

  sol.permutation("ABC");

  return 0;
}