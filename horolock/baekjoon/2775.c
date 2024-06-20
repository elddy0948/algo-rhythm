#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_FLOOR_ROOM      15

int main(void)
{
    int test_case = 0, tc = 0, i = 0;
    int floor = 0, room = 0;
    int rooms[MAX_FLOOR_ROOM][MAX_FLOOR_ROOM];

    scanf("%d", &test_case);

    for (i = 0; i < 15; ++i)
        rooms[0][i] = i;
    
    for (i = 0; i < 15; ++i)
        rooms[i][0] = 0;

    
    for (i = 1; i <= 14; ++i) {
        for (int j = 1; j <= 14; ++j) {
            rooms[i][j] = rooms[i - 1][j] + rooms[i][j - 1];
        }
    }

    for (tc = 0; tc < test_case; ++tc) {
        scanf("%d\n%d", &floor, &room);
        printf("%d\n", rooms[floor][room]);
    }

    return 0;
}