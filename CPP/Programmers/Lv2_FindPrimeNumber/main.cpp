#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

int solution(string numbers)
{
    int answer = 0;
    vector<int> integer_numbers;
    set<int> prime_numbers;

    for (int i = 0; i < numbers.length(); i++)
    {
        integer_numbers.push_back(numbers[i] - '0');
    }

    sort(integer_numbers.begin(), integer_numbers.end());

    for (int r = 1; r <= numbers.length(); r++)
    {
        do
        {
            string temp = "";
            int number_to_check = 0;
            bool isPrime = true;
            int check_range = 0;

            for (int i = 0; i < r; i++)
            {
                temp += to_string(integer_numbers[i]);
            }

            number_to_check = stoi(temp);

            if (number_to_check <= 1)
            {
                continue;
            }

            check_range = (int)sqrt(number_to_check);

            for (int i = 2; i <= check_range; i++)
            {
                if (number_to_check % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
            {
                prime_numbers.insert(number_to_check);
            }
        } while (next_permutation(integer_numbers.begin(), integer_numbers.end()));
    }

    answer = prime_numbers.size();

    return answer;
}

int main()
{
    cout << solution("011");
    return 0;
}