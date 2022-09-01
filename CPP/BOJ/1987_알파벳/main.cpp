#include <iostream>
#include <algorithm>

const int MAX = 21;

char board[MAX][MAX];
bool visited[26];
int r, c;
int maximumSteps = -1;
int dx[] = {1, 0, -1, 0}; //동 북 서 남
int dy[] = {0, -1, 0, 1}; // 동 북 서 남

int Bigger(int lhs, int rhs)
{
    if (lhs > rhs)
    {
        return lhs;
    }
    return rhs;
}

void Input()
{
    std::cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            std::cin >> board[i][j];
        }
    }
}

void DFS(int y, int x, int steps)
{
    maximumSteps = std::max(maximumSteps, steps);

    for (int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x >= 0 && next_y >= 0 && next_x < c && next_y < r)
        {
            if (visited[board[next_y][next_x] - 'A'] == false)
            {
                visited[board[next_y][next_x] - 'A'] = true;
                DFS(next_y, next_x, steps + 1);
                visited[board[next_y][next_x] - 'A'] = false;
            }
        }
    }
}

int main(void)
{
    Input();
    visited[board[0][0] - 'A'] = true;
    DFS(0, 0, 1);
    std::cout << maximumSteps;
    return 0;
}