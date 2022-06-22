#include <iostream>

int func(int n, int r, int c)
{
    if (n == 0)
    {
        return 0;
    }

    int half = 1 << (n - 1);

    // 1번 사각형
    if (r < half && c < half)
    {
        return func(n - 1, r, c);
    }
    // 2번 사각형
    if (r < half && c >= half)
    {
        return half * half + func(n - 1, r, c - half);
    }
    // 3번 사각형
    if (r >= half && c < half)
    {
        return 2 * half * half + func(n - 1, r - half, c);
    }
    // 4번 사각형
    if (r >= half && c >= half)
    {
        return 3 * half * half + func(n - 1, r - half, c - half);
    }

    return 0;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, r, c;

    std::cin >> n >> r >> c;

    std::cout << func(n, r, c);

    return 0;
}