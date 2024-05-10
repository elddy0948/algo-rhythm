#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_SIZE       1000001

typedef long long ll;

int comparator(const void* lhs, const void* rhs)
{
    ll l = *(const ll*)lhs;
    ll r = *(const ll*)rhs;

    return l > r;
}

ll* treeLengths = NULL;

int main(void)
{
    int treeCount = 0, i = 0;
    ll minimumHeight = 0, length = 0, max = 0;
    ll low = 0, high = 0;

    scanf("%d %lld", &treeCount, &minimumHeight);

    treeLengths = (ll*)malloc(sizeof(ll) * treeCount);

    for (i = 0; i < treeCount; ++i)
    {
        scanf("%lld", &treeLengths[i]);
    }

    qsort(treeLengths, treeCount, sizeof(ll), comparator);

    high = treeLengths[treeCount - 1];

    while (low <= high)
    {
        ll sum = 0;
        ll mid = (low + high) / 2;

        for (i = 0; i < treeCount; ++i)
        {
            if (treeLengths[i] - mid > 0) { sum += (treeLengths[i] - mid); }
        }
        if (sum >= minimumHeight)
        {
            max = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("%lld", max);

    return 0;
}