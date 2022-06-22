#include <iostream>

int n, m;
int arr[9];
int is_visited[9];

void func(int k)
{
    if (k == m)
    {
        // 만든 수열의 길이 m
        for (int i = 0; i < m; i++)
        {
            //만든 수열 출력
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!is_visited[i])
        {
            arr[k] = i;
            is_visited[i] = true;
            func(k + 1);
            is_visited[i] = false;
        }
    }
}

int main(void)
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n >> m;
    func(0);
}