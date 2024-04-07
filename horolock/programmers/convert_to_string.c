#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int n) {
    unsigned int divider = 10000;
    unsigned int length = 0;
    char* answer = (char*)malloc(5 * sizeof(char) + 1);
    unsigned char flag = 0;

    while(divider != 1)
    {
        if(flag == 0 && (n / divider == 0))
        {
            divider /= 10;
            continue;
        }
        flag = 1;
        answer[length++] = (n / divider) + '0';
        n %= divider;
        divider /= 10;
    }

    answer[length++] = n + '0';
    answer[length] = '\0';

    return answer;
}
