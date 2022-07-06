#include <iostream>
#include <queue>

const int MAX = 101;

typedef struct
{
    int y, x, z;
} Dir;

Dir moveDir[6] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

int M, N, H;
int tomatoBoxes[MAX][MAX][MAX];
std::queue<std::pair<std::pair<int, int>, int>> q;
int noTomato;

bool allRipe(void)
{
    int possibleTomatoes = M * N * H - noTomato;
    int count = 0;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (tomatoBoxes[j][k][i] == 1)
                {
                    count++;
                }
            }
        }
    }

    return possibleTomatoes == count;
}

int bfs(void)
{
    int day = 0;

    if (q.empty())
    {
        return -1;
    }

    while (!q.empty())
    {
        int currentSize = q.size();

        for (int i = 0; i < currentSize; i++)
        {
            int y = q.front().first.first;
            int x = q.front().first.second;
            int z = q.front().second;

            for (int j = 0; j < 6; j++)
            {
                int nextY = y + moveDir[j].y;
                int nextX = x + moveDir[j].x;
                int nextZ = z + moveDir[j].z;

                if (nextX >= 0 && nextY >= 0 && nextZ >= 0 && nextX < M && nextY < N && nextZ < H)
                {
                    if (tomatoBoxes[nextY][nextX][nextZ] == 0)
                    {
                        tomatoBoxes[nextY][nextX][nextZ] = 1;
                        q.push(std::make_pair(std::make_pair(nextY, nextX), nextZ));
                    }
                }
            }
            q.pop();

            if (q.size() == 0 && allRipe())
            {
                return day;
            }
            else if (q.size() == 0 && !allRipe())
            {
                return -1;
            }
        }
        day++;
    }
}

int main()
{
    std::cin >> M >> N >> H;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                std::cin >> tomatoBoxes[j][k][i];
                if (tomatoBoxes[j][k][i] == 1)
                {
                    q.push(std::make_pair(std::make_pair(j, k), i));
                }
                if (tomatoBoxes[j][k][i] == -1)
                {
                    noTomato++;
                }
            }
        }
    }

    if (q.size() == M * N * H - noTomato)
    {
        std::cout << 0;
    }
    else
    {
        int result = bfs();
        std::cout << result;
    }
    return 0;
}