#include <iostream>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int a;
  int b;
  cin >> a >> b;

  for (int h = 0; h < b; h++)
  {
    for (int w = 0; w < a; w++)
    {
      cout << '*';
    }
    cout << '\n';
  }
  return 0;
}