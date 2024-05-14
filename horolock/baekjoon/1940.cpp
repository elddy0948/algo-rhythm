#include <iostream>
#include <algorithm>

using namespace std;

#define MATERIAL_MAX        15000

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned int materialCount = 0, armorNeeded = 0, i = 0, lhs = 0, rhs = 0, sum = 0, answer = 0;
    unsigned int* materials = nullptr;

    cin >> materialCount;
    cin >> armorNeeded;

    lhs = 0;
    rhs = materialCount - 1;

    materials = new unsigned int[materialCount];

    for(i = 0; i < materialCount; ++i)
    {
        cin >> materials[i];
    }

    sort(materials, materials + materialCount);

    while (lhs < rhs)
    {
        sum = materials[lhs] + materials[rhs];
        if (sum == armorNeeded)
        {
            answer++;
            lhs++;
            rhs--;
        }
        else if (sum > armorNeeded)
        {
            rhs--;
        }
        else if (sum < armorNeeded)
        {
            lhs++;
        }
    }

    cout << answer;

    delete materials;

    return 0;
}