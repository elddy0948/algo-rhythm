#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<string, int> combinations[11];
int ordered_counts[11];

void combination(string order_history, int index, string current_combination)
{
    if (index == order_history.size())
    {
        int menu_count = current_combination.size();
        combinations[menu_count][current_combination]++;
        ordered_counts[menu_count] = max(ordered_counts[menu_count], combinations[menu_count][current_combination]);
        return;
    }

    combination(order_history, index + 1, current_combination + order_history[index]);
    combination(order_history, index + 1, current_combination);
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for (auto order : orders)
    {
        sort(order.begin(), order.end());
        combination(order, 0, "");
    }

    for (auto menu_count : course)
    {
        for (auto menu_info : combinations[menu_count])
        {
            if (menu_info.second == ordered_counts[menu_count] && menu_info.second >= 2)
            {
                answer.push_back(menu_info.first);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<string> a{"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<int> b{2, 3, 4};

    vector<string> answer = solution(a, b);

    for (auto menu : answer)
    {
        cout << menu << " ";
    }
}