#include <stdio.h>

int main(void)
{
    int tc, test_case;
    int lhs, rhs;
    scanf("%d", &test_case);

    for (int tc = 1; tc <= test_case; ++tc)
    {
        scanf("%d %d", &lhs, &rhs);
        printf("Case #%d: %d\n", tc, lhs + rhs);
    }
    return 0;
}