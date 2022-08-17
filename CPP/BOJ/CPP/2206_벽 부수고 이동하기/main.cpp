#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>

const int dx[4] = {0, 0, -1, 1}; // 상 하 좌 우
const int dy[4] = {-1, 1, 0, 0};

int map[1002][1002];
int distance[1001][1001];
bool visited[1002][1002][2];
int n, m;

typedef struct
{
    int y, x;
    int didBreakWall;
} PositionInfo;

void Input()
{
    std::cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
}

int BFS()
{
    std::queue<PositionInfo> q;
    int answer = -1;

    q.push(PositionInfo{1, 1, 0});
    visited[1][1][0] = visited[1][1][1] = true;
    distance[1][1] = 1;

    while (!q.empty())
    {
        PositionInfo positionInfo = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = positionInfo.x + dx[i];
            int nextY = positionInfo.y + dy[i];

            if (nextX > 0 && nextY > 0 && nextX <= m && nextY <= n)
            {
                if (map[nextY][nextX] == 1 && !positionInfo.didBreakWall && !visited[nextY][nextX][positionInfo.didBreakWall + 1])
                {
                    visited[nextY][nextX][positionInfo.didBreakWall + 1] = true;
                    distance[nextY][nextX] = distance[positionInfo.y][positionInfo.x] + 1;
                    q.push(PositionInfo{nextY, nextX, 1});
                }
                if (map[nextY][nextX] == 0 && !visited[nextY][nextX][positionInfo.didBreakWall])
                {
                    visited[nextY][nextX][positionInfo.didBreakWall] = true;
                    distance[nextY][nextX] = distance[positionInfo.y][positionInfo.x] + 1;
                    q.push(PositionInfo{nextY, nextX, positionInfo.didBreakWall});
                }
                if (nextY == n && nextX == m)
                {
                    answer = distance[nextY][nextX];
                    return answer;
                }
            }
        }
    }

    return answer;
}

int main(void)
{
    Input();
    if (n == 1 && m == 1)
    {
        std::cout << 1;
        return 0;
    }

    int answer = BFS();

    std::cout << answer;

    return 0;
}