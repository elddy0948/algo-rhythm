#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_VERTEX_SIZE         1001
#define VISITED                 1

struct Edge {
    int connections[MAX_VERTEX_SIZE];
    int connection_size;
};

static struct Edge edge_map[MAX_VERTEX_SIZE];
char visited[MAX_VERTEX_SIZE];

void DFS(int vertex)
{
    if (visited[vertex])
        return;

    visited[vertex] = VISITED;
    
    for (int i = 0; i < edge_map[vertex].connection_size; ++i) {
        int connected_vertex = edge_map[vertex].connections[i];
        if (!visited[connected_vertex]) {
            DFS(connected_vertex);
        }
    }
    return;
}

int main(void)
{
    int vertex_size = 0, edge_size = 0, i = 0;
    int vertex1 = 0, vertex2 = 0;
    int answer = 0;

    scanf("%d %d", &vertex_size, &edge_size);

    for (i = 0; i < edge_size; ++i) {
        scanf("%d %d", &vertex1, &vertex2);

        edge_map[vertex1].connections[edge_map[vertex1].connection_size++] = vertex2;
        edge_map[vertex2].connections[edge_map[vertex2].connection_size++] = vertex1;
    }

    for (i = 1; i <= vertex_size; ++i) {
        if (!visited[i]) {
            DFS(i);
            answer++;

        }
    }

    printf("%d", answer);

    return 0;
}
