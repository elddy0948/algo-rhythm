#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> packs(10001, 0);
std::vector<int> dp(1001, 0);
int cardsToBuy;

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> cardsToBuy;

	for (int i = 1; i <= cardsToBuy; i++) { std::cin >> packs[i]; }

	for (int i = 1; i <= cardsToBuy; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = std::max(dp[i], dp[i - j] + packs[j]);
		}
	}

	std::cout << dp[cardsToBuy];

	return 0;
}