#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool visited[10];
char signs[10];
std::vector<std::string> available;
int k;

bool SignCheck(char a, char b, char sign) 
{
	if (sign == '<') 
	{
		if (a > b) return false;
	}
	else if (sign == '>')
	{
		if (a < b) return false;
	}
	return true;
}

void Comb(int length, std::string number)
{
	if (length == k + 1)
	{
		available.push_back(number);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (visited[i]) { continue; }

		if (length == 0 || SignCheck(number[length - 1], i + '0', signs[length - 1])) 
		{
			visited[i] = true;
			Comb(length + 1, number + std::to_string(i));
			visited[i] = false;
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> k;

	for (int i = 0; i < k; i++) 
	{
		std::cin >> signs[i];
	}

	Comb(0, "");
	std::sort(available.begin(), available.end());
	std::cout << available[available.size() - 1] << '\n' << available[0];

	return 0;
}