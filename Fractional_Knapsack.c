// Fractional Knapsack Program

#include <stdio.h>

int main() {
    int n , capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int weight[n], value[n];
    float ratio[n], x[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the weight and value of item %d: ", i + 1);
        scanf("%d %d", &weight[i], &value[i]);
        ratio[i] = (float)value[i] / weight[i];
        x[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {

                // Swap Ratio
                float tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;

                // Swap Weight
                int tempWeight = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tempWeight;

                // Swap Value
                int tempValue = value[j];
                value[j] = value[j + 1];
                value[j + 1] = tempValue;
            }
        }
    }

    float totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + weight[i] <= capacity) {
            x[i] = 1;
            currentWeight += weight[i];
            totalValue += value[i];
        } else {
            int remaining_capacity = capacity - currentWeight;
            x[i] = (float)remaining_capacity / weight[i];
            totalValue += ratio[i] * remaining_capacity;
            break;
        }
    }

    printf("Maximum value in Knapsack = %.2f\n", totalValue);
    return 0;
}

/*
Output Example:
Enter the number of items: 3
Enter the capacity of the knapsack: 50
Enter the weight and value of item 1: 10 60
Enter the weight and value of item 2: 20 100
Enter the weight and value of item 3: 30 120
Maximum value in Knapsack = 240.00
*/