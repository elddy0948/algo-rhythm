#include <stdio.h>
#include <math.h>

#define MIN(lhs, rhs) ((lhs < rhs) ? lhs : rhs)

typedef struct
{
	unsigned int Sour;
	unsigned int Bitter;
} Food;

Food foods[10];

int main()
{
	int n;
	int i = 0;
	int s = 1, b = 0, j = 0;
	int ans = 2147483647;
	scanf_s("%d", &n);

	for (i = 0; i < n; ++i)
	{
		scanf_s("%d %d", &foods[i].Sour, &foods[i].Bitter);
	}

	for (i = 1; i < (1 << n); ++i)
	{
		s = 1, b = 0, j = 0;
		for (j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				s *= foods[j].Sour;
				b += foods[j].Bitter;
			}
		}

		ans = MIN(ans, abs(s - b));
	}

	printf("%d\n", ans);

	return 0;
}