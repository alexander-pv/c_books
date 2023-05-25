#include <stdio.h>
#include <stdlib.h>

#define MAXARRAY 10


void quicksort(int arr[], int low, int high);

void print_array(int arr[], int size);


void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

void quicksort(int arr[], int low, int high) {
    int i = low;
    int j = high;
    int tmp;
    // Pivot element
    int pivot = arr[(low + high) / 2];
    // Partition
    do {
        // Find element lower and higher than pivot
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        // Switch two elements
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);

    // Recursion
    if (low < j) {
        quicksort(arr, low, j);
    }
    if (i < high) {
        quicksort(arr, i, high);
    }
}


int main(void) {
    // Create array of integers
    int array[MAXARRAY] = {0};
    for (int i = 0; i < MAXARRAY; i++) {
        array[i] = rand() % 100;
    }
    printf("Before sort:\n");
    print_array(array, MAXARRAY);
    quicksort(array, 0, (MAXARRAY - 1));
    printf("After sort:\n");
    print_array(array, MAXARRAY);

    return 0;
}