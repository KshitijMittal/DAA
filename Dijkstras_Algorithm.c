// Dijkstra's Algorithm 

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 9999

int main() {
    int graph[MAX][MAX], dist[MAX], visited[MAX], n, src;
    int i, j, count, minDist, next;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for no edge):\n", INF);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    // Initialization
    for (i = 0; i < n; i++) {
        dist[i] = graph[src][i];
        visited[i] = 0;
    }
    dist[src] = 0;
    visited[src] = 1;

    for (count = 1; count < n; count++) {
        minDist = INF;
        for (i = 0; i < n; i++)
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                next = i;
            }

        visited[next] = 1;

        for (i = 0; i < n; i++)
            if (!visited[i] && dist[next] + graph[next][i] < dist[i])
                dist[i] = dist[next] + graph[next][i];
    }

    printf("Shortest distances from vertex %d:\n", src);
    for (i = 0; i < n; i++)
        printf("To %d = %d\n", i, dist[i]);

return 0;
}