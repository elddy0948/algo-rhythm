#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> subsets(vector<int> &nums)
  {
    numbers = nums;

    answer.emplace_back(vector<int>{});

    vector<int> vec{};
    BackTracking(vec, 0);

    return answer;
  }

private:
  void BackTracking(vector<int> nums, int index)
  {
    if (nums.size() == numbers.size())
    {
      return;
    }

    for (int i = index; i < numbers.size(); i++)
    {
      nums.push_back(numbers[i]);
      answer.emplace_back(nums);
      BackTracking(nums, i + 1);
      nums.pop_back();
    }
  }

private:
  vector<int> numbers;
  vector<vector<int>> answer;
};

int main(void)
{
  Solution sol;

  vector<int> inp{0};
  auto vectors = sol.subsets(inp);

  for (auto &vec : vectors)
  {
    cout << "[ ";

    for (int i = 0; i < vec.size(); i++)
    {
      cout << vec[i] << ',';
    }
    cout << " ]";
  }

  return 0;
}