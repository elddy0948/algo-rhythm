#include <iostream>
#include <vector>

using namespace std;

#define MAX_COMPUTER_SIZE       101

vector<vector<int>> computer_map(MAX_COMPUTER_SIZE, vector<int>());
bool visited[MAX_COMPUTER_SIZE];
int answer = 0;

void dfs(int computer)
{
    visited[computer] = true;

    for (int c = 0; c < computer_map[computer].size(); ++c) {
        int available_computer = computer_map[computer][c];
        if (!visited[available_computer]) {
            answer++;
            dfs(available_computer);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int number_of_computers = 0, network_size = 0, n = 0;
    int computer1 = 0, computer2 = 0;

    cin >> number_of_computers;
    cin >> network_size;

    for (n = 0; n < network_size; ++n) {
        cin >> computer1 >> computer2;
        computer_map[computer1].push_back(computer2);
        computer_map[computer2].push_back(computer1);
    }

    dfs(1);

    cout << answer;

    return 0;
}