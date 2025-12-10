// Write a program to solve the Traveling salesman problem using Greedy Method.

#include <stdio.h>
#include <limits.h>
#define MAX 10
int n; // Number of cities
int cost[MAX][MAX]; // Cost matrix
int visited[MAX]; // Visited cities
int min_cost = 0; // Minimum cost of the tour

void tsp(int curr_pos) {
    visited[curr_pos] = 1;
    int next_city = -1;
    int min_edge = INT_MAX;

    // Find the next city with the minimum cost edge
    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[curr_pos][i] && cost[curr_pos][i] < min_edge) {
            min_edge = cost[curr_pos][i];
            next_city = i;
        }
    }

    // If there is a next city, visit it
    if (next_city != -1) {
        min_cost += min_edge;
        tsp(next_city);
    } else {
        // Return to starting city
        if (cost[curr_pos][0]) {
            min_cost += cost[curr_pos][0];
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

    tsp(0); // Start TSP from the first city

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