#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) 
  {
     
    if (empty(digits))
    {
      return {};
    }
    
    vector<string> result;
    string cur;

    letterCombinations(digits, &cur, &result);

    return result;
  }

private:
  void letterCombinations(const string& digits, string* cur, vector<string>* result)
  {
    static const vector<string> letterLookup = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    if (size(*cur) == size(digits))
    {
      result->emplace_back(*cur);
      return;
    }

    auto digitIndex = size(*cur);

    for (auto& c : letterLookup[digits[digitIndex] - '0'])
    {
      cur->push_back(c);
      letterCombinations(digits, cur, result);
      cur->pop_back();
    }
  }
};


int main(void)
{
  Solution sol;

  for (auto result : sol.letterCombinations("23"))
  {
    cout << result << '\n';
  }

  return 0;
}