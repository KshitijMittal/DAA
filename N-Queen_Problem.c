// Write a program to implement N Queen's problem using Back Tracking.

#include <stdio.h>
#define N 4
int board[N][N];
int solutions = 0;

int is_safe(int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

void solve_nq_util(int col) {
    if (col >= N) {
        solutions++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (is_safe(i, col)) {
            board[i][col] = 1; // Place queen

            solve_nq_util(col + 1); // Recur to place rest of the queens

            board[i][col] = 0; // Backtrack
        }
    }
}

int main() {
    // Initialize the board
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    solve_nq_util(0);
    printf("Total solutions for %d-Queens: %d\n", N, solutions);
    return 0;
}