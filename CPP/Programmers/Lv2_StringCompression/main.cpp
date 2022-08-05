#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s)
{
    int answer = s.length();
    int string_size = s.length();

    for (int i = 1; i <= (string_size / 2); i++)
    {
        string match_string = s.substr(0, i);
        int match_count = 1;
        string res = "";

        for (int j = i; j < string_size; j += i)
        {
            if (match_string == s.substr(j, i))
            {
                match_count++;
            }
            else
            {
                if (match_count > 1)
                {
                    res += to_string(match_count);
                }
                res += match_string;
                match_string = s.substr(j, i);
                match_count = 1;
            }
        }

        if (match_count > 1)
        {
            res += to_string(match_count);
        }
        res += match_string;
        answer = min(answer, (int)res.length());
    }
    return answer;
}

int main(void)
{
    int answer = solution("abcabcabcabcdededededede");
    // std::cout << answer;
    string s = "abcasdfas";
    std::cout << "Hello";
    std::cout << s.substr(2, 0);
}