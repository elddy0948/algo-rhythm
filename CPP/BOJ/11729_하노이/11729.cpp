#include <iostream>

void func(int a, int b, int n)
{
    if (n == 1)
    {
        std::cout << a << ' ' << b << '\n';
        return;
    }

    func(a, 6 - a - b, n - 1);
    std::cout << a << ' ' << b << '\n';
    func(6 - a - b, b, n - 1);
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int k;
    std::cin >> k;

    std::cout << (1 << k) - 1 << '\n';
    func(1, 3, k);
}