#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_LENGTH      101
#define DIV             1000000000

int stair[MAX_LENGTH][10]; 

int main(void)
{
    int length = 0, l = 0;
    int answer = 0;

    scanf("%d", &length);

    stair[1][0] = 0;
    
    for (l = 1; l <= 9; ++l) {
        stair[1][l] = 1;
    }

    for (l = 2; l <= length; ++l) {
        stair[l][0] = stair[l - 1][1] % DIV;
        for (int j = 1; j <= 8; ++j) {
            stair[l][j] = (stair[l - 1][j - 1] + stair[l - 1][j + 1]) % DIV;
        }
        stair[l][9] = stair[l - 1][8] % DIV;
    }

    for (l = 0; l <= 9; ++l) {
        answer = (answer + stair[length][l]) % DIV;
    }

    printf("%d", answer);

    return 0;
}