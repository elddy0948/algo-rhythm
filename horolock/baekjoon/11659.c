#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100001

int main(void)
{
	int* arr = (int*)malloc(MAX_SIZE * sizeof(int));
	

	int i = 0, from = 0, to = 0, n = 0, m = 0;

	arr[0] = 0;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; ++i)
	{
		int input = 0;
		scanf("%d", &input);

		arr[i] = arr[i - 1] + input;
	}

	for (i = 0; i < m; ++i)
	{
		scanf("%d %d", &from, &to);
		printf("%d\n", arr[to] - arr[from - 1]);
	}

	return 0;
}