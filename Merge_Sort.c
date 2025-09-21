// Program to implement Merge Sort algorithm using Divide and Conquer approach

 #include <stdio.h>

    void merge(int arr[], int left, int mid, int right) {
        int i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                i++;
            } else {
                int value = arr[j];
                int index = j;

                // Shift all elements between i and j-1 right by one
                while (index > i) {
                    arr[index] = arr[index - 1];
                    index--;
                }
                arr[i] = value;

                // Update pointers
                i++;
                mid++;
                j++;
            }
        }
    }

    void mergeSort(int arr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    void printArray(int arr[], int size) {
        for (int i = 0; i < size; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }

    int main() {
        int arr[] = {64, 34, 25, 12, 22, 11, 90};
        int n = sizeof(arr) / sizeof(arr[0]);

        printf("Original array: \n");
        printArray(arr, n);

        mergeSort(arr, 0, n - 1);

        printf("Sorted array: \n");
        printArray(arr, n);

        return 0;
    }