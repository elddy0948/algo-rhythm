// https: // en.cppreference.com/w/cpp/algorithm/next_permutation

#include <iostream>
#include <string>
#include <algorithm>

void StringNextPermutation(std::string str)
{
  std::sort(str.begin(), str.end());
  do
  {
    std::cout << str << '\n';
  } while (std::next_permutation(str.begin(), str.end()));
}

void Pick(int *arr)
{
  do
  {
    for (int i = 0; i < 4; i++)
    {
      if (arr[i] == 0)
        std::cout << i + 1;
    }
    std::cout << '\n';
  } while (std::next_permutation(arr, arr + 4));
}

int main(void)
{
  std::string str = "dba";

  StringNextPermutation(str);
  // abd
  // adb
  // bad
  // bda
  // dab
  // dba

  int arr[4] = {0, 0, 1, 1};

  Pick(arr);
  // 12
  // 13
  // 14
  // 23
  // 24
  // 34

  return 0;
}