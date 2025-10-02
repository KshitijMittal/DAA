// Floyd Warshell Algorithm
/*
FLOYD_WARSHELL ()
for k ← 1 to n do
    for i ← 1 to n do
        for j ← 1 to n do
            if d[i, k] + d[k, j] < d[i, j] then
                d[i, j] ← d[i, k] + d[k, j]
                p[i, j] ← p[k, j]
return d, p
*/

#include <stdio.h>
#define INF 99999

void floydWarshell(int graph[][10], int n) {
    int dist[10][10], i, j, k;

    // Initialize the distance matrix with the input graph
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshell algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    printf("Shortest distance matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[10][10], n, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for infinity):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshell(graph, n);

    return 0;
}