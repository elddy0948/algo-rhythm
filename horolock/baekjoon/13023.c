/**
 * BOJ 13023
 * ABCDE
 * Search
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_PEOPLE_SIZE     2001
#define VISITED             1
#define NOT_VISITED         0
#define FOUND               1
#define NOT_FOUND           0

struct Relationship_info {
    int relationships[MAX_PEOPLE_SIZE];
    int size;
};

static struct Relationship_info relationship_map[MAX_PEOPLE_SIZE];
static char visited[MAX_PEOPLE_SIZE];
static int found_flag = NOT_FOUND;

void dfs(int person, int depth)
{
    if (depth == 5) {
        found_flag = FOUND;
        return;
    }

    visited[person] = VISITED;

    for (int i = 0; i < relationship_map[person].size; ++i) {
        int available_person = relationship_map[person].relationships[i];

        if (!visited[available_person]) {
            dfs(available_person, depth + 1);
        }
    }

    visited[person] = NOT_VISITED;

    return;
}

int main(void)
{
    int person_size = 0, relationship_size = 0, i = 0;
    int person1 = 0, person2 = 0;

    scanf("%d %d", &person_size, &relationship_size);

    for (i = 0; i < relationship_size; ++i) {
        scanf("%d %d", &person1, &person2);
        relationship_map[person1].relationships[relationship_map[person1].size++] = person2;
        relationship_map[person2].relationships[relationship_map[person2].size++] = person1;
    }

    for (i = 0; i < person_size; ++i) {
        dfs(i, 1);
        if (found_flag == FOUND) {
            break;
        }
    }

    (found_flag == FOUND) ? printf("1") : printf("0");

    return 0;
}