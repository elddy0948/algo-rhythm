#include <iostream>

int n, m;
int sequence_arr[8];

void create_sequence(int current_sequence_length)
{
    if (current_sequence_length == m)
    {
        for (int i = 0; i < current_sequence_length; i++)
        {
            std::cout << sequence_arr[i] << ' ';
        }
        std::cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        sequence_arr[current_sequence_length] = i;
        create_sequence(current_sequence_length + 1);
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;

    create_sequence(0);

    return 0;
}