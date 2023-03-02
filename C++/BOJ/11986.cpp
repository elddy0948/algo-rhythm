#include <iostream>
#include <vector>

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  long result = 0;
  std::vector<long> numbers(n + 1, 0);
  std::vector<long> sums(n + 1, 0);
  std::vector<long> remainders(m, 0);

  std::cin >> sums[0];

  for (int i = 1; i < n; i++)
  {
    std::cin >> numbers[i];
    sums[i] = sums[i - 1] + numbers[i];
  }

  for (int i = 0; i < n; i++)
  {
    int remainder = sums[i] % m;

    if (remainder == 0)
    {
      result++;
    }

    remainders[remainder]++;
  }

  for (int i = 0; i < m; i++)
  {
    result += ((remainders[i] * (remainders[i] - 1)) / 2);
  }

  std::cout << result;

  return 0;
}