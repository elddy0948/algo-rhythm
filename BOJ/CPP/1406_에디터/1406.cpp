#include <iostream>
#include <string>
#include <stack>

int main()
{
    int n;
    std::string s;

    std::cin >> s;
    std::cin >> n;
    std::stack<char> s1, s2;

    for (auto &x : s)
    {
        s1.push(x);
    }

    while (n--)
    {
        char op;
        std::cin >> op;

        if (op == 'L')
        {
            if (!(s1.empty()))
            {

                s2.push(s1.top());
                s1.pop();
            }
        }
        else if (op == 'D')
        {
            if (!s2.empty())
            {

                s1.push(s2.top());
                s2.pop();
            }
        }
        else if (op == 'B')
        {
            if (!(s1.empty()))
            {
                s1.pop();
            }
        }
        else if (op == 'P')
        {
            char x;
            std::cin >> x;
            s1.push(x);
        }
    }
    while (!(s1.empty()))
    {
        s2.push(s1.top());
        s1.pop();
    }
    while (!(s2.empty()))
    {
        std::cout << s2.top();
        s2.pop();
    }
    return 0;
}