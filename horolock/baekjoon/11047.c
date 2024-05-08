#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N_MAX       11

int main(void)
{
    int coin_count = 0;
    int target = 0;
    int i = 0;
    int coins[N_MAX];
    int answer = 0;

    scanf("%d %d", &coin_count, &target);

    for(i = 0; i < coin_count;++i)
    {
        scanf("%d", &coins[i]);
    }

    i = coin_count - 1;

    while (target > 0)
    {
        if (coins[i] <= target)
        {
            answer++;
            target -= coins[i];
        }
        else
        {
            i--;
        }
    }

    printf("%d", answer);

    return 0;
}