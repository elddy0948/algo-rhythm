#include <iostream>

int dp[100004];
int array[100004];
int n, m;

void get_input()
{
    std::cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        std::cin >> array[i];
        dp[i] = dp[i - 1] + array[i];
    }
}

int get_sum_between(int lhs, int rhs)
{
    return dp[rhs] - dp[lhs - 1];
}

void get_input_and_print_sum()
{
    for (int i = 0; i < m; i++)
    {
        int lhs, rhs;
        std::cin >> lhs >> rhs;
        std::cout << get_sum_between(lhs, rhs) << '\n';
    }
}

int main(void)
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    dp[0] = 0;
    get_input();
    get_input_and_print_sum();
    return 0;
}