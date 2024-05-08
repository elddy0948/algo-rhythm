#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_LENGTH	1000001
#define MAX_NUM		1001

typedef long long ll;

ll arr[MAX_LENGTH];
ll remain_arr[MAX_NUM];

int main(void)
{
	int n = 0, m = 0, i = 0;
	ll answer = 0;
	ll now = 0;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &arr[i]);
		arr[i] += arr[i - 1];
		arr[i] %= m;
		remain_arr[arr[i]]++;
	}

	answer = remain_arr[0];

	for (i = 0; i < m; ++i)
	{
		now = remain_arr[i];
		answer += ((now * (now - 1)) / 2);
	}

	printf("%lld", answer);

	return 0;
}