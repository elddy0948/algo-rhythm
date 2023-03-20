#include <vector>
#include <iostream>
using namespace std;

vector<int> numbers;
int answer = 0;

bool isPrime(int n)
{
  if (n <= 1)
    return false;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

void backtracking(int sum, int count, int index)
{

  if (count == 3)
  {
    if (isPrime(sum))
      answer++;
    return;
  }

  if (index == numbers.size())
    return;

  backtracking(sum + numbers[index], count + 1, index + 1);
  backtracking(sum, count, index + 1);
}

int solution(vector<int> nums)
{
  numbers = nums;
  backtracking(0, 0, 0);
  return answer;
}

int main()
{
  vector<int> input = {1, 2, 3, 4};

  solution(input);

  return 0;
}