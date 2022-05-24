#include <iostream>
#include <algorithm>

int main()
{
    int houses[1001][3];
    int cost[3];
    int n = 0;

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;

    houses[0][0] = 0, houses[0][1] = 0, houses[0][2] = 0;

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> cost[0] >> cost[1] >> cost[2];
        houses[i][0] = std::min(houses[i - 1][1], houses[i - 1][2]) + cost[0];
        houses[i][1] = std::min(houses[i - 1][0], houses[i - 1][2]) + cost[1];
        houses[i][2] = std::min(houses[i - 1][0], houses[i - 1][1]) + cost[2];
    }

    std::cout << std::min(houses[n][0], std::min(houses[n][1], houses[n][2]));

    return 0;
}