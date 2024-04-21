#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// 중복으로 빼주는 부분은 꼭 더해준다.

int sum_arr[1025][1025];

int main(void)
{
	sum_arr[0][0] = 0;
	int table_size = 0;
	int test_case = 0;
	int w = 0, h = 0;
	int input = 0;

	scanf("%d %d", &table_size, &test_case);

	for (h = 1; h <= table_size; ++h)
	{
		for (w = 1; w <= table_size; ++w)
		{
			scanf("%d", &input);
			sum_arr[h][w] = sum_arr[h - 1][w] + sum_arr[h][w - 1] - sum_arr[h - 1][w - 1] + input;
		}
	}

	for (w = 0; w < test_case; ++w)
	{
		int x1, y1, x2, y2;

		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		
		int ans = sum_arr[y2][x2] - sum_arr[y1 - 1][x2] - sum_arr[y2][x1 - 1] + sum_arr[y1 - 1][x1 - 1];

		printf("%d\n", ans);
	}

	return 0;
}