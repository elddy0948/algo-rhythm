#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name)
{
    int answer = 0;
    int first = -1, last = -1;
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] != 'A')
        { // A가 아닐 때 문자 변환 카운트
            answer += min((int)('Z' - name[i]) + 1, (int)(name[i] - 'A'));
        }
        else
        { // A면 first, last 인덱스 구하기
            if (first == -1)
            {
                first = i - 1;
            }
            if (last == -1 && first != -1)
                for (int j = i + 1; j < name.length(); j++)
                {
                    if (name[j] != 'A')
                    {
                        last = j;
                        break;
                    }
                }
        }
    }

    if (first == -1 && last == -1) // last,first 둘 다 없는 경우
        answer += name.length() - 1;
    else
    {
        if (first != -1 && last == -1) // last만 있는 경우
            return answer += first;
        else if (first == -1 && last != -1) // first만 있는 경우
            return answer += name.length() - last;
        else
        { // last, first 둘 다 있는 경우
            int dis = min(first * 2 + (name.length() - last), (name.length() - last) * 2 + first);
            return answer += min((int)name.length() - 1, dis);
        }
    }
}

int main()
{
    int answer = solution("BBBAAAAABAAAAAAAAAAA");
    printf("%d", answer);
    return 0;
}