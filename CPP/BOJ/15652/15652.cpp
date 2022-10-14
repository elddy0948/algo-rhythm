#include <iostream>
#include <vector>

int n, m;
std::vector<int> vec(8, 0);

void CreateSequence(int length, int currentNumber)
{
  if (length == m)
  {
    for (int i = 0; i < length; i++)
      std::cout << vec[i] << ' ';
    std::cout << '\n';

    return;
  }

  for (int i = currentNumber; i <= n; i++)
  {
    vec[length] = i;
    CreateSequence(length + 1, vec[length]);
  }
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    vec[0] = i;
    CreateSequence(1, i);
  }

  return 0;
}