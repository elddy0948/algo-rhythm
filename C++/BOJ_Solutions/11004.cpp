#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;

    cin >> n >> k;

    vector<int> numbers(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    cout << numbers[k - 1];

    return 0;
}