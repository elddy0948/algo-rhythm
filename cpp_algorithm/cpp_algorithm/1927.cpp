#include <iostream>
#include<queue>
#include <vector>
#include <stdio.h>

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::priority_queue <int, std::vector<int>, std::greater<int>> pq;

	int num;
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		if (num >= 1) {
			pq.push(num);
		}
		else if (num == 0) 
		{
			if (pq.empty()) 
			{
				printf("0\n");
			}
			else 
			{
				printf("%d\n", pq.top());
				pq.pop();
			}

		}
	}
	return 0;
}