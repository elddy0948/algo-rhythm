#include <stdio.h>
#include <string.h>

#define ADD(S, x) (S |= (1 << x))
#define REMOVE(S, x) (S &= ~(1 << x))
#define CHECK(S, x) (S & (1 << x))
#define TOGGLE(S, x) (S ^= (1 << x))
#define ALL(S) (S = (1 << 21) - 1)
#define EMPTY(S) (S = 0)

#define MAX_OP_SIZE 7
#define TRUE 1
#define FALSE 0

int main()
{
	int instruction_count;
	int i;
	int S = 0;

	scanf_s("%d", &instruction_count);

	for (i = 0; i < instruction_count; ++i)
	{
		char op[MAX_OP_SIZE] = { '\0' };
		int operand = 0;

		scanf_s("%s", op, MAX_OP_SIZE);
		scanf_s("%d", &operand);

		if (!strcmp(op, "add"))
		{
			ADD(S, operand);
		}
		else if (!strcmp(op, "remove"))
		{
			REMOVE(S, operand);
		}
		else if (!strcmp(op, "check"))
		{
			int res = CHECK(S, operand);;
			(res > 0) ? printf("1\n") : printf("0\n");
		}
		else if (!strcmp(op, "toggle"))
		{
			TOGGLE(S, operand);
		}
		else if (!strcmp(op, "all"))
		{
			ALL(S);
		}
		else if (!strcmp(op, "empty"))
		{
			EMPTY(S);
		}
	}

	return 0;
}