#include <iostream>
#include <queue>
#include <algorithm>

const int MAX_SIZE = 8;
typedef struct
{
    int y;
    int x;
} Direction;

Direction move_direction[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m;
int labs_map[MAX_SIZE][MAX_SIZE];
int temp[MAX_SIZE][MAX_SIZE];
int result_safe_area;

void BFS()
{
    int after_spread_virus[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            after_spread_virus[i][j] = temp[i][j];
        }
    }
    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (after_spread_virus[i][j] == 2)
            {
                q.push(std::make_pair(i, j));
            }
        }
    }

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_y = y + move_direction[i].y;
            int next_x = x + move_direction[i].x;

            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n)
            {
                if (after_spread_virus[next_y][next_x] == 0)
                {
                    after_spread_virus[next_y][next_x] = 2;
                    q.push(std::make_pair(next_y, next_x));
                }
            }
        }
    }

    int safe_area = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (after_spread_virus[i][j] == 0)
            {
                safe_area++;
            }
        }
    }

    result_safe_area = std::max(result_safe_area, safe_area);
}

void makeWall(int wall_count)
{
    if (wall_count == 3)
    {
        BFS();
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] == 0)
            {
                temp[i][j] = 1;
                makeWall(wall_count + 1);
                temp[i][j] = 0;
            }
        }
    }
}

void copyMaps()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp[i][j] = labs_map[i][j];
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> labs_map[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (labs_map[i][j] == 0)
            {
                copyMaps();
                temp[i][j] = 1;
                makeWall(1);
                temp[i][j] = 0;
            }
        }
    }

    std::cout << result_safe_area;

    return 0;
}