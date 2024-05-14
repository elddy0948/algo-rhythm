#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned int N = 0, i = 0, lhs = 0, rhs = 0, sum = 0, count = 0;

    cin >> N;

    lhs = 1;
    rhs = 1;
    sum = 1;

    while(rhs != N)
    {
        if (sum == N)
        {
            count += 1;
            rhs += 1;
            sum = sum + rhs;
        }
        else if (sum > N)
        {
            sum = sum - lhs;
            lhs += 1;
        }
        else if (sum < N)
        {
            rhs += 1;
            sum = sum + rhs;
        }
    }

    cout << count + 1 << '\n';

    return 0;
}