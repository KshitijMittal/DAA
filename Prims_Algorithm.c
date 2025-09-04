// Prim's Algorithm according to the the pseduocode below
/*
MST_PRIM(G, w, r)
1  for each u ∈ V[G]
2      key[u] ← ∞
3      π[u] ← NIL
4  key[r] ← 0
5  Q ← V[G]
6  while Q ≠ ∅
7      u ← EXTRACT-MIN(Q)
8      for each v ∈ G.Adj[u]
9          if v ∈ Q and w(u, v) < key[v]
10             π[v] ← u
11             key[v] ← w(u, v)
12 return π
*/

// ...existing code...
#include <stdio.h>
#define MAX 100
#define INF 1000000000

struct Edge {
    int u, v, weight;
};

/* Implements Prim exactly following the pseudocode:
   - uses key[], π (parent[]), and Q represented by inQ[]
   - builds adjacency from the edge list so the main() stays like Kruskal's code
*/
void Prim(struct Edge edges[], int n, int vertices) {
    int adj[MAX][MAX];
    int key[MAX], parent[MAX], inQ[MAX];

    // initialize adjacency matrix
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (i == j) adj[i][j] = 0;
            else adj[i][j] = INF;
        }
    }
    // fill adjacency from edge list (undirected)
    for (int i = 0; i < n; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            if (w < adj[u][v]) { // keep smallest if multiple edges
                adj[u][v] = w;
                adj[v][u] = w;
            }
        }
    }

    // Pseudocode initialization: key[] <- INF, π[] <- NIL, Q <- V[G]
    for (int i = 0; i < vertices; ++i) {
        key[i] = INF;
        parent[i] = -1; // NIL
        inQ[i] = 1;     // vertex is in Q
    }
    key[0] = 0; // choose root r = 0

    // while Q != ∅
    for (int iter = 0; iter < vertices; ++iter) {
        // u <- EXTRACT-MIN(Q)
        int u = -1;
        int minKey = INF;
        for (int v = 0; v < vertices; ++v) {
            if (inQ[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }
        if (u == -1) break; // remaining vertices unreachable
        inQ[u] = 0; // remove u from Q

        // for each v in G.Adj[u]
        for (int v = 0; v < vertices; ++v) {
            if (adj[u][v] != INF && inQ[v] && adj[u][v] < key[v]) {
                parent[v] = u;       // π[v] <- u
                key[v] = adj[u][v]; // key[v] <- w(u,v)
            }
        }
    }

    // Print MST edges and total cost (skip vertices with parent == -1)
    printf("Edges in the Minimum Spanning Tree:\n");
    int totalCost = 0;
    for (int v = 0; v < vertices; ++v) {
        if (parent[v] != -1) {
            printf("%d -- %d == %d\n", parent[v], v, key[v]);
            totalCost += key[v];
        }
    }
    printf("Total cost of Minimum Spanning Tree: %d\n", totalCost);
}

int main() {
    int n, vertices;
    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    if (scanf("%d", &vertices) != 1) return 1;
    printf("Enter number of edges: ");
    if (scanf("%d", &n) != 1) return 1;

    for (int i = 0; i < n; i++) {
        printf("Enter edge %d (u v weight): ", i + 1);
        if (scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight) != 3) return 1;
    }

    Prim(edges, n, vertices);

    return 0;
}