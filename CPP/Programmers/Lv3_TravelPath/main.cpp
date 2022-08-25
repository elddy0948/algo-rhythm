#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<string>> sorted_tickets;

bool dfs(string from, vector<string> &answer, vector<bool> &is_used_ticket, int used_tickets_count)
{
    answer.push_back(from);

    if (used_tickets_count == sorted_tickets.size())
    {
        return true;
    }

    for (int i = 0; i < sorted_tickets.size(); i++)
    {
        vector<string> ticket = sorted_tickets[i];

        if (ticket.front() == from && is_used_ticket[i] == false)
        {
            is_used_ticket[i] = true;
            bool can_travel = dfs(ticket.back(), answer, is_used_ticket, used_tickets_count + 1);

            if (can_travel)
            {
                return true;
            }

            is_used_ticket[i] = false;
        }
    }
    answer.pop_back();

    return false;
}

bool compare(vector<string> lhs, vector<string> rhs)
{
    return lhs.back() < rhs.back();
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;
    vector<bool> visited(tickets.size(), false);

    sort(tickets.begin(), tickets.end(), compare);
    sorted_tickets = tickets;

    dfs("ICN", answer, visited, 0);

    return answer;
}

int main()
{
    vector<vector<string>> input{{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};
    // vector<vector<string>> input{{"ICN", "AOO"}, {"AOO", "BOO"}, {"BOO", "COO"}, {"COO", "DOO"}, {"DOO", "EOO"}, {"EOO", "DOO"}, {"DOO", "COO"}, {"COO", "BOO"}, {"BOO", "AOO"}};

    vector<string> ans = solution(input);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}