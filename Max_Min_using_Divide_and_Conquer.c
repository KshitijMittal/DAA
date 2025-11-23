// Program to find maximum and minimum in an array using Divide and Conquer approach
/*
                        Pseudocode Algorithm:
Start
Global variables
global_min = 0
global_max = 0

function find_max_min(arr, low, high)
    if low == high then
        if arr[low] > global_max then
            global_max = arr[low]
        if arr[low] < global_min then
            global_min = arr[low]
    else if high == low + 1 then
        if arr[low] > arr[high] then
            if arr[low] > global_max then
                global_max = arr[low]
            if arr[high] < global_min then
                global_min = arr[high]
        else
            if arr[high] > global_max then
                global_max = arr[high]
            if arr[low] < global_min then
                global_min = arr[low]
    else
        mid = (low + high) / 2
        find_max_min(arr, low, mid)
        min1 = global_min
        max1 = global_max
        find_max_min(arr, mid + 1, high)
        min2 = global_min
        max2 = global_max

        global_min = min(min1, min2)
        global_max = max(max1, max2)
    return (global_min, global_max)
*/

#include <stdio.h>

int global_min, global_max;

void find_max_min(int arr[], int low, int high) {
    if (low == high) {
        // Case 1: Only one element
        if (arr[low] > global_max)
            global_max = arr[low];
        if (arr[low] < global_min)
            global_min = arr[low];
    }
    else if (high == low + 1) {
        // Case 2: Two elements
        if (arr[low] > arr[high]) {
            if (arr[low] > global_max)
                global_max = arr[low];
            if (arr[high] < global_min)
                global_min = arr[high];
        } else {
            if (arr[high] > global_max)
                global_max = arr[high];
            if (arr[low] < global_min)
                global_min = arr[low];
        }
    }
    else {
        // Case 3: More than two elements
        int mid = (low + high) / 2;

        // First half
        find_max_min(arr, low, mid);
        int min1 = global_min;
        int max1 = global_max;

        // Second half
        find_max_min(arr, mid + 1, high);
        int min2 = global_min;
        int max2 = global_max;

        // Update global values
        global_min = (min1 < min2) ? min1 : min2;
        global_max = (max1 > max2) ? max1 : max2;
    }
}

int main() {
    int arr[] = {12, 3, 45, 7, 19, -5, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Initialize global_min and global_max
    global_min = arr[0];
    global_max = arr[0];

    find_max_min(arr, 0, n - 1);

    printf("Minimum: %d\n", global_min);
    printf("Maximum: %d\n", global_max);

    return 0;
}

/*
Output Example:
Minimum: -5
Maximum: 100
*/