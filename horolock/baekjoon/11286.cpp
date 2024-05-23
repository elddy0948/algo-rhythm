#include <iostream>
#include <queue>

using namespace std;

struct compare {
    bool operator() (int lhs, int rhs) {
        int lhs_abs = abs(lhs);
        int rhs_abs = abs(rhs);

        if (lhs_abs == rhs_abs) { return lhs > rhs; }
        else { return lhs_abs > rhs_abs; }
    }
};

int main(void)
{
    priority_queue<int, vector<int>, compare> pq;
    int operator_size = 0, i = 0, op = 0;

    cin >> operator_size;

    for (i = 0; i < operator_size; ++i) {
        cin >> op;

        if (op == 0) {
            if (pq.empty()) { 
                cout << "0\n"; 
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(op);
        }
    }

    return  0;
}