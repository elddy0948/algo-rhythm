#include <unordered_map>
#include <iostream>
#include <string>

int main(void)
{
	int n, m;
	std::unordered_map<std::string, int> dictionary;
	std::cin >> n >> m;
	std::string pocketmons[100001];

	std::cin.tie(0);
	std::ios_base::sync_with_stdio(0);

	for (int i = 1; i <= n; i++)
	{
		std::cin >> pocketmons[i];

		dictionary.insert(std::make_pair(pocketmons[i], i));
	}

	for (int i = 0; i < m; i++)
	{
		std::string inp;
		std::cin >> inp;

		if (std::isdigit(inp[0]) != 0)
		{
			int intInput = std::stoi(inp);
			std::cout << pocketmons[intInput] << '\n';
		}
		else
		{
			auto index = dictionary.find(inp);
			std::cout << index->second << '\n';
		}
	}

	return 0;
}