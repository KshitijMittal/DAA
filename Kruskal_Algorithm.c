// Kruskal Algorithm

#include <stdio.h>
#define MAX 100

struct Edge {
    int u, v, weight;
};

int parent[MAX];
// Find parent with path compression
int find (int i) {
    while (i != parent[i])
        i = parent[i];
    return i;
}

// Union of two subsets
void UnionSets (int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void Kruskal (struct Edge edges[], int n, int vertices) {
    int i, count = 0, totalCost = 0;
    // Initialize parent array
    for (i = 0; i < vertices; i++)
        parent[i] = i;
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < n && count < vertices - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            printf("%d -- %d == %d\n", u, v, edges[i].weight);
            totalCost += edges[i].weight;
            UnionSets(u, v);
            count++;
        }
    }
    printf("Total cost of Minimum Spanning Tree: %d\n", totalCost);
}

void SortEdges(struct Edge edges[], int n) {
    struct Edge temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (edges[j].weight > edges[j+1].weight) {
                temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, vertices;
    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter edge %d (u v weight): ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    SortEdges(edges, n);
    Kruskal(edges, n, vertices);

    return 0;
}