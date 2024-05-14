#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned int numberSize = 0, i = 0, lhs = 0, rhs = 0, answer = 0;
    long* numbers = nullptr;
    long target = 0, sum = 0;

    cin >> numberSize;

    numbers = new long[numberSize];

    for (i = 0; i < numberSize; ++i)
    {
        cin >> numbers[i];
    }

    sort(numbers, numbers + numberSize);

    for (i = 0; i < numberSize; ++i)
    {
        target = numbers[i];
        lhs = 0;
        rhs = numberSize - 1;

        while (lhs < rhs)
        {
            sum = numbers[lhs] + numbers[rhs];
            if (sum == target)
            {
                if (lhs != i && rhs != i)
                {
                    answer++;
                    break;
                }
                else if (lhs == i) { lhs++; }
                else if (rhs == i) { rhs--; }
            }
            else if (sum < target) { lhs++; }
            else { rhs--; }
        }
    }

    cout << answer;

    delete numbers;

    return 0;
}