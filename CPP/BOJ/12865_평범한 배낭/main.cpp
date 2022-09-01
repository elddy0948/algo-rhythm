#include <iostream>
#include <algorithm>

typedef struct
{
    int weight;
    int value;
} Product;

const int MAX_Products_Count = 101;
const int MAX_Weight = 100001;

int dp[MAX_Products_Count][MAX_Weight];
Product products[MAX_Products_Count];

int products_count;
int available_weight;

void Input()
{
    std::cin >> products_count >> available_weight;
    for (int i = 1; i <= products_count; i++)
    {
        std::cin >> products[i].weight >> products[i].value;
    }
}

void Solve()
{
    for (int i = 1; i <= products_count; i++)
    {
        for (int j = 1; j <= available_weight; j++)
        {
            if (j >= products[i].weight)
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - products[i].weight] + products[i].value);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
}

int main(void)
{
    Input();
    Solve();
    std::cout << dp[products_count][available_weight];
}