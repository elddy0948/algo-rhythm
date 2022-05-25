#include <string>
#include <vector>

using namespace std;

int answer = 50;
bool visited[51];

bool check_difference(string lhs, string rhs)
{
    int difference_count = 0;
    for (int i = 0; i < lhs.size(); i++)
    {
        if (lhs[i] != rhs[i])
        {
            difference_count++;
        }

        if (difference_count > 1)
        {
            return false;
        }
    }
    if (difference_count == 1)
    {
        return true;
    }
    return false;
}

void dfs(string begin, string target, vector<string> words, int level)
{
    if (answer <= level)
    {
        return;
    }

    if (begin == target)
    {
        answer = min(answer, level);
        return;
    }

    for (int i = 0; i < words.size(); i++)
    {
        if (check_difference(begin, words[i]) && !visited[i])
        {
            visited[i] = true;
            dfs(words[i], target, words, level + 1);
            visited[i] = false;
        }
    }
    return;
}

int solution(string begin, string target, vector<string> words)
{
    dfs(begin, target, words, 0);

    if (answer == 50)
    {
        return 0;
    }

    return answer;
}