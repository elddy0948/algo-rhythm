#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
    unsigned int sequence_length = 0;
    stack<int> s;
    int i = 0, popped_index = 0;

    cin >> sequence_length;

    vector<int> arr = vector<int>(sequence_length, 0);
    vector<int> answer = vector<int>(sequence_length, 0);

    for (i = 0; i < sequence_length; ++i) {
        cin >> arr[i];
    }

    i = 0;

    while (i != sequence_length) {
        if (s.empty()) {
            s.push(i++);
            continue;
        }

        if (arr[i] > arr[s.top()]) {
            popped_index = s.top();
            s.pop();
            answer[popped_index] = arr[i];
        } else if (arr[i] <= arr[s.top()]) {
            s.push(i++);
        }
    }

    while (!s.empty()) {
        answer[s.top()] = -1;
        s.pop();
    }

    for (i = 0; i < sequence_length; ++i) {
        cout << answer[i] << ' ';
    }

    return 0;
}