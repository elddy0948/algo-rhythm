#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int test_case = 0;
    int tc = 0, i = 0;
    int left_side = 0, right_side = 0;
    long long available_bridges = 0;

    scanf("%d", &test_case);

    for (tc = 0; tc < test_case; ++tc) {
        available_bridges = 1;

        scanf("%d %d", &left_side, &right_side);

        for (i = 0; i < left_side; ++i) {
            available_bridges *= (right_side - i);
            available_bridges /= (i + 1);
        }

        printf("%lld\n", available_bridges);
    }

    return 0;
}