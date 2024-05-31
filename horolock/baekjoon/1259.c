#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH      100000

int main(void)
{
    char inp[MAX_LENGTH];
    int i = 0;
    size_t length = 0;
    char flag = 0;

    for (;strcmp(inp, "0"); scanf("%s", inp)) {
        length = strlen(inp);
        if (length == 0) { continue; }

        for (i = 0; i < length / 2; ++i) {
            if (inp[i] != inp[length - 1 - i]) {
                flag = 1;
                break;
            }
        }

        (flag == 1) ? printf("no\n") : printf("yes\n");
        flag = 0;
    }

    return 0;
}