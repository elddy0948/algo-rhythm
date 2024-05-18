#include <iostream>
#include <deque>

using namespace std;

typedef pair<int, int> Node;    // index, number

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0, L = 0, i = 0;
    int curr = 0;

    cin >> N >> L;
    deque<Node> dq;

    for(i = 0; i < N; ++i)
    {
        cin >> curr;
        while (dq.size() && (dq.back().first > curr))
        {
            dq.pop_back();
        }
        Node n = Node(curr, i);
        dq.push_back(n);
        if (dq.front().second <= i - L) { dq.pop_front(); }
        cout << dq.front().first << ' ';
    }

    return 0;
}