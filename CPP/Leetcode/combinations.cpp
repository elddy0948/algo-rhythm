#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> combine(int n, int k)
  {
    this->n = n;
    maxSize = k;

    vector<int> comb;

    for (int i = 1; i <= n; i++)
    {
      vector<int> comb{i};
      BackTracking(comb);
    }

    return answer;
  }

private:
  void BackTracking(vector<int> &comb)
  {
    if (comb.size() == maxSize)
    {
      answer.emplace_back(comb);
      return;
    }

    for (int i = comb.back() + 1; i <= n; i++)
    {
      comb.push_back(i);
      BackTracking(comb);
      comb.pop_back();
    }
    return;
  }

private:
  vector<vector<int>> answer;
  int n;
  int maxSize;
};

int main(void)
{
  Solution sol;

  for (auto result : sol.combine(1, 1))
  {
    for (auto element : result)
    {
      cout << element << ' ';
    }
    cout << '\n';
  }

  return 0;
}