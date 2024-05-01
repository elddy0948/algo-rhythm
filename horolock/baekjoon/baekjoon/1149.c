#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define min(x, y) ((x) < (y) ? (x) : (y))

#define MAX_HOUSES		1001
#define MAX_COLORS		3		// 0 : R , 1 : G , 2 : B

int houses[MAX_COLORS][MAX_HOUSES];
int dp[MAX_COLORS][MAX_HOUSES];

int main(void)
{
	int i = 0;
	int house_count = 0;
	int answer = 0;

	scanf("%d", &house_count);

	for (i = 0; i < house_count; ++i)
	{
		scanf("%d %d %d", &houses[0][i], &houses[1][i], &houses[2][i]);
	}

	dp[0][0] = houses[0][0];
	dp[1][0] = houses[1][0];
	dp[2][0] = houses[2][0];
	
	for (i = 1; i < house_count; ++i)
	{
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + houses[0][i];
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + houses[1][i];
		dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + houses[2][i];
	}

	answer = min(dp[0][house_count - 1], min(dp[1][house_count - 1], dp[2][house_count - 1]));

	printf("%d", answer);

	return 0;
}