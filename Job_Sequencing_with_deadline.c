// Job Sequencing with Deadlines

#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    int deadline[n], profit[n], job[n];
    for (int i = 0; i < n; i++) {
        printf("Enter deadline and profit of job %d: ", i + 1);
        scanf("%d %d", &deadline[i], &profit[i]);
        job[i] = i + 1;  // Job IDs
    }

    // Sort jobs by profit in descending order (bubble sort, minimal change)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {
                // Swap job IDs
                int tempjob = job[j];
                job[j] = job[j + 1];
                job[j + 1] = tempjob;

                // Swap deadline
                int tempdeadline = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = tempdeadline;

                // Swap profit
                int tempprofit = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tempprofit;
            }
        }
    }

    // Find maximum deadline
    int max_deadline = deadline[0];
    for (int i = 1; i < n; i++) {
        if (deadline[i] > max_deadline) {
            max_deadline = deadline[i];
        }
    }

    int totalprofit = 0;
    int k = 0;
    int current_deadline = max_deadline;
    int scheduled_idx[n];   // store the sorted-index of each scheduled job

    // Pseudo-code scheduling (kept as in your version)
    for (int i = 0; i < n; i++) {
        if (deadline[i] <= current_deadline) {
            totalprofit += profit[i];
            scheduled_idx[k++] = i;   // store index i (in sorted arrays)
            current_deadline -= deadline[i];
        }
    }

    // Print scheduled jobs using stored indices
    printf("Scheduled jobs: ");
    for (int i = 0; i < k; i++) {
        printf("J%d ", job[scheduled_idx[i]]); // job[id] gives original job number
    }

    // Print total profit expression using the actual scheduled profits
    printf("\nTotal Profit = (");
    for (int i = 0; i < k; i++) {
        printf("%d", profit[scheduled_idx[i]]);
        if (i < k - 1) printf("+");
    }
    printf(") = %d\n", totalprofit);

    return 0;
}

/*
Output Example:
Enter the number of jobs: 4
Enter deadline and profit of job 1: 2 100
Enter deadline and profit of job 2: 1 19
Enter deadline and profit of job 3: 2 27
Enter deadline and profit of job 4: 1 25
Scheduled jobs: J1 J3
Total Profit = (100+27) = 127
*/