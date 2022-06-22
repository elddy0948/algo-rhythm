#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool visited[201];
vector<vector<int>> global_computers;

void dfs(int computer_number)
{
    visited[computer_number] = true;

    for (int i = 0; i < global_computers[computer_number].size(); i++)
    {
        if (i == computer_number)
        {
            continue;
        }

        if (global_computers[computer_number][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    global_computers = computers;

    for (int i = 0; i < global_computers.size(); i++)
    {
        if (!visited[i])
        {
            dfs(i);
            answer++;
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> inp{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
    cout << solution(3, inp);
    return 0;
}