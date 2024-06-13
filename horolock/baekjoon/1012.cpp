/**
 * BOJ 1012
 * 유기농 배추
 * Search
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const char x_direction[4] = {0, 0, -1, 1};
const char y_direction[4] = {-1, 1, 0, 0};

int m = 0;
int n = 0;

void bfs(vector<vector<bool>> &map, int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});

    map[y][x] = false;

    while (!q.empty())
    {
        int x_pos = q.front().first;
        int y_pos = q.front().second;

        q.pop();

        for (int d = 0; d < 4; ++d)
        {
            int new_x = x_pos + x_direction[d];
            int new_y = y_pos + y_direction[d];

            if (new_x >= 0 && new_y >= 0 && new_x <= m && new_y <= n)
            {
                if (map[new_y][new_x] == true)
                {
                    q.push({new_x, new_y});
                    map[new_y][new_x] = false;
                }
            }
        }
    }
}


int main(void)
{
    int test_case = 0;
    int x_pos = 0, y_pos = 0;
    int k = 0;

    cin >> test_case;

    for (int i = 0; i < test_case; ++i)
    {
        int answer = 0;
        cin >> m >> n >> k;

        vector<vector<bool>> cabbage_map(n + 1, vector<bool>(m + 1, 0));

        for (int pos = 0; pos < k; ++pos)
        {
            cin >> x_pos >> y_pos;

            cabbage_map[y_pos][x_pos] = true;
        }

        for (int x = 0; x <= m; ++x)
        {
            for (int y = 0; y <= n; ++y)
            {
                if (cabbage_map[y][x] == true)
                {
                    bfs(cabbage_map, x, y);
                    answer++;
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}