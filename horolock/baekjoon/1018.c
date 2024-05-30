#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void)
{
    char white_pattern[2][2] = {
        {'W', 'B'},
        {'B', 'W'}
    };

    char black_pattern[2][2] = {
        {'B', 'W'},
        {'W', 'B'}
    };

    int n = 0, m = 0, i = 0, j = 0;
    int start_with_white = 0, start_with_black = 0;
    char chess_board[50][50];

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; ++i) {
        scanf("%s", chess_board[i]);
    }
    int answer = 2501;
    int min = 2501;

    for (i = 0; i < n - 7; ++i) {
        for (j = 0; j < m - 7; ++j) {
            
            for (int x = i; x < i + 8; ++x) {
                for (int y = j; y < j + 8; ++y) {
                    if (chess_board[x][y] != white_pattern[x % 2][y % 2])
                        start_with_white++;
                    if (chess_board[x][y] != black_pattern[x % 2][y % 2])
                        start_with_black++;
                }
            }

            min = (start_with_black > start_with_white ? start_with_white : start_with_black);
            if (answer > min)
                answer = min;

            start_with_white = 0;
            start_with_black = 0;
        }
    }

    printf("%d", answer);

    return 0;
}