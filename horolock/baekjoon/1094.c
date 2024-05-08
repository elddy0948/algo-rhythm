#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	unsigned int x = 0;
	unsigned int answer = 0;

	scanf("%d", &x);

	while (x > 0)
	{
		if (x % 2 == 1)
		{
			++answer;
		}
		x /= 2;
	}

	printf("%d", answer);

	return 0;
}