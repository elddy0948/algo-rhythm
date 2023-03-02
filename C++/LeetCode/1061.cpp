#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  string smallestEquivalentString(string s1, string s2, string baseStr)
  {
    string result;
    v = vector<int>(26, 0);

    for (int i = 0; i < v.size(); i++)
    {
      v[i] = i;
    }

    for (int i = 0; i < s1.length(); i++)
    {
      unionSet(s1[i] - 'a', s2[i] - 'a');
    }

    for (int i = 0; i < baseStr.length(); i++)
    {
      const auto &parent = findSet(baseStr[i] - 'a');
      result.push_back(parent + 'a');
    }

    return result;
  }

private:
  int findSet(const int element)
  {
    if (v[element] == element)
    {
      return element;
    }
    else
    {
      return v[element] = findSet(v[element]);
    }
  }

  void unionSet(const int lhs, const int rhs)
  {
    int lhsRoot = findSet(lhs);
    int rhsRoot = findSet(rhs);

    if (lhsRoot != rhsRoot)
    {
      v[max(lhsRoot, rhsRoot)] = min(lhsRoot, rhsRoot);
    }

    return;
  }

private:
  vector<int> v;
};

int main()
{
  Solution sol;
  string res = sol.smallestEquivalentString("parker", "morris", "parser");
  cout << res;
  return 0;
}