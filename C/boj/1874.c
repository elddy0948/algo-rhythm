#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 200100

struct Stack
{
  int top;
  unsigned capacity;
  unsigned int* arr;
};

struct Stack* create_stack(unsigned capacity)
{
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->arr = (unsigned int*)malloc(stack->capacity * sizeof(unsigned int) + 1);
  return stack;
}

int is_full(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;
}

int is_empty(struct Stack* stack)
{
  return stack->top == -1;
}

void push(struct Stack* stack, int item)
{
	if(is_full(stack)) { return; }

  stack->arr[++stack->top] = item;
}

unsigned int pop(struct Stack* stack)
{
	if(is_empty(stack)) { return 0; }

  return stack->arr[stack->top--];
}

unsigned int peek(struct Stack* stack)
{
	if(is_empty(stack)) { return 0; }
  return stack->arr[stack->top];
}

int main(void)
{
  unsigned int n, i = 0;
	unsigned char flag = 0;
	unsigned int target = 0;
	unsigned int top = 0;
	unsigned int current_number = 1;
	unsigned int command_index = 0;

	unsigned char command[MAX_LENGTH] = {};

  scanf("%d", &n);
  
	struct Stack* stack = create_stack(n);
	
	for(i = 0; i < n; ++i)
	{
		scanf("%d", &target);
		top = peek(stack);

		if(target >= current_number)
		{
			for(;target >= current_number; ++current_number)
			{
				push(stack, current_number);
				command[command_index++] = '+';
			}
			pop(stack);
			command[command_index++] = '-';
		}
		else
		{
			top = peek(stack);

			if(top > target)
			{
				flag = 1;
				break;
			}

			pop(stack);
			command[command_index++] = '-';
		}
	}

	if(flag == 1)
	{
		printf("NO");
	}
	else
	{
		for(i = 0; i < command_index; ++i)
		{
			printf("%c\n", command[i]);
		}
	}

  return 0;
}
