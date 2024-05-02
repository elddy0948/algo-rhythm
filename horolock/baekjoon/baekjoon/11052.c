#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define ARRAY_SIZE		1001

#define max(x, y) ((x) > (y) ? (x) : (y))

int card_count = 0;
int card_value = 0;

int i = 0;
int n = 0;
int a = 0;

int arr[ARRAY_SIZE];
int dp[ARRAY_SIZE];

int main(void)
{
	scanf("%d", &card_count);

	for (i = 1; i <= card_count; ++i)
	{
		scanf("%d", &arr[i]);
	}
	
	for (n = 1; n <= card_count; ++n)
	{
		for (a = 1; a <= n; ++a)
		{
			dp[n] = max(dp[n], dp[n - a] + arr[a]);
		}
	}

	printf("%d", dp[card_count]);

	return 0;
}