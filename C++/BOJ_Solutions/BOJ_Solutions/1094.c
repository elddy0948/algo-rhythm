#include <stdio.h>

int main()
{
	unsigned char stick = 0x40;
	unsigned char temp = 0x00;
	unsigned char i = 0;
	int to_find = 0;
	unsigned char counter = 0;

	scanf_s("%d", &to_find);

	for (i = 0; i < 7; ++i)
	{
		if (to_find == (stick | temp))
		{
			temp |= stick;
			++counter;
			break;
		}
		else if (to_find > (stick | temp))
		{
			temp |= stick;
			++counter;
		}
		stick = (stick >> 1);
	}

	printf("%d\n", counter);

	return 0;
}