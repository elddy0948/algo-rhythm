#include <iostream>
#include <list>

int solve1406() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  std::string init_string;
  std::cin >> init_string;
  
  std::list<char> L;

  for (auto c : init_string)
  {
    L.push_back(c);
  }
  auto cursor = L.end();

  int q;
  std::cin >> q;

  while (q--)
  {
    char op;
    std::cin >> op;
    
    if (op == 'P')
    {
      char char_to_add;
      std::cin >> char_to_add;
      L.insert(cursor, char_to_add);
    }
    else if (op == 'L')
    {
      if (cursor != L.begin())
      {
        cursor--;
      }
    }
    else if (op == 'D')
    {
      if (cursor != L.end())
      {
        cursor++;
      }
    }
    else if (op == 'B')
    {
      if (cursor != L.begin())
      {
        cursor--;
        L.erase(cursor);
      }
    }
  }
  for (auto c : L)
  {
    std::cout << c;
  }
  return 0;
}
