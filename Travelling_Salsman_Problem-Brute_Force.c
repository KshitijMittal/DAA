// Write a program to solve the Traveling salesman problem using brute force method.

#include <stdio.h>
#include <limits.h>
#define MAX 10
int n; // Number of cities
int cost[MAX][MAX]; // Cost matrix
int visited[MAX]; // Visited cities
int min_cost = INT_MAX; // Minimum cost of the tour

void tsp(int curr_pos, int count, int cost_so_far) {
    // If all cities have been visited and we are back at the starting city
    if (count == n && cost[curr_pos][0]) {
        int total_cost = cost_so_far + cost[curr_pos][0];
        if (total_cost < min_cost) {
            min_cost = total_cost;
        }
        return;
    }

    // Explore all cities
    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[curr_pos][i]) {
            visited[i] = 1;
            tsp(i, count + 1, cost_so_far + cost[curr_pos][i]);
            visited[i] = 0; // Backtrack
        }
    }
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    visited[0] = 1; // Start from the first city

    tsp(0, 1, 0); // Start TSP from the first city

    printf("Minimum cost of travelling salesman tour: %d\n", min_cost);
    return 0;
}

/*
Output Example:
Enter number of cities: 4
Enter cost matrix:
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
Minimum cost of travelling salesman tour: 80
*/