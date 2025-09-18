// 0-1 Knapsack Algorithm
/*
Dynamic-0-1-Knapsack (v, w, n, W)
for l ← 0 to W
    c[0, l] ← 0
for i ← 1 to n
    c[i, 0] ← 0
    for l ← 1 to W
        if w[i] ≤ l then
            if v[i] + c[i − 1, l − w[i]] > c[i − 1, l] then
                c[i, l] ← v[i] + c[i − 1, l − w[i]]
            else
                c[i, l] ← c[i − 1, l]
        else
            c[i, l] ← c[i − 1, l]
return c[n, W]
*/

#include <stdio.h>
#define MAX 105

int c[MAX][MAX];

int knapsack(int W, int wt[], int val[], int n) {
    int i, l;

    // Initialize base cases
    for (l = 0; l <= W; l++) {
        c[0][l] = 0;
    }
    for (i = 1; i <= n; i++) {
        c[i][0] = 0;
        for (l = 1; l <= W; l++) {
            if (wt[i - 1] <= l) {
                if (val[i - 1] + c[i - 1][l - wt[i - 1]] > c[i - 1][l])
                    c[i][l] = val[i - 1] + c[i - 1][l - wt[i - 1]];
                else
                    c[i][l] = c[i - 1][l];
            } else {
                c[i][l] = c[i - 1][l];
            }
        }
    }
    return c[n][W];
}

// Print DP table
void printTable(int n, int W) {
    printf("\nDP Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int l = 0; l <= W; l++) {
            printf("%3d ", c[i][l]);
        }
        printf("\n");
    }
}

// Print optimal items for solution
void printOptimalItems(int wt[], int val[], int n, int W) {
    int res = c[n][W];
    int w = W;
    int picked = 0;   // track whether any item was picked

    printf("\nItems included in the optimal solution:\n");
    for (int i = n; i > 0 && res > 0; i--) {
        if (res != c[i - 1][w]) {
            printf("Item %d (Weight: %d, Value: %d)\n", i, wt[i - 1], val[i - 1]);
            res -= val[i - 1];
            w -= wt[i - 1];
            picked = 1;  // at least one item picked
        }
    }
    if (!picked) {
        printf("No items included.\n");
    }
    printf("\n");
}

int main() {
    int n, W, i;
    int val[MAX], wt[MAX];

    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights and values of items:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &wt[i]);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &val[i]);
    }
    printf("Enter maximum weight of knapsack: ");
    scanf("%d", &W);

    int result = knapsack(W, wt, val, n);

    printTable(n, W);

    printf("\nMaximum value in Knapsack = %d\n", result);

    printOptimalItems(wt, val, n, W);

    return 0;
}
