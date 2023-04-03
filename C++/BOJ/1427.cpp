#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  string inp;
  cin >> inp;

  vector<int> numbers(inp.size(), 0);

  for (int i = 0; i < inp.size(); i++)
  {
    numbers[i] = stoi(inp.substr(i, 1));
  }

  for (int i = 0; i < inp.length(); i++)
  {
    int max_number = i;

    for (int j = i + 1; j < inp.length(); j++)
    {
      if (numbers[j] > numbers[max_number])
      {
        max_number = j;
      }
    }
    if (numbers[i] < numbers[max_number])
    {
      int tmp = numbers[i];
      numbers[i] = numbers[max_number];
      numbers[max_number] = tmp;
    }
  }

  for (const auto &n : numbers)
  {
    cout << n;
  }

  return 0;
}