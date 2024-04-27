#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_N		41

typedef struct ZeroOne
{
	int zero_count;
	int one_count;
} ZeroOne;

ZeroOne fib[MAX_N];

int main(void)
{
	int test_case = 0;
	int i = 0, number = 0;

	scanf("%d", &test_case);

	fib[0].zero_count = 1;
	fib[0].one_count = 0;

	fib[1].zero_count = 0;
	fib[1].one_count = 1;

	for (i = 2; i < MAX_N; ++i)
	{
		fib[i].zero_count = fib[i - 1].zero_count + fib[i - 2].zero_count;
		fib[i].one_count = fib[i - 1].one_count + fib[i - 2].one_count;
	}

	for (i = 0; i < test_case; ++i)
	{
		scanf("%d", &number);
		printf("%d %d\n", fib[number].zero_count, fib[number].one_count);
	}

	return 0;
}