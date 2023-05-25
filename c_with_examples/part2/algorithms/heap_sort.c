#include <stdio.h>
#include <stdlib.h>

// MAx array length
#define MAXARRAY 5

// Main heapsort function
void heapsort(int *ar, int len);

// Helps heapsort() to push elements starting from 'pos' position
void heapbubble(int pos, int *ar, int len);

// Fill array with random integers
void fill_array(int *ar);

// Display array
void print_array(int *ar);


void print_array(int *ar) {
    for (int i = 0; i < MAXARRAY; i++) {
        printf(" %d ", ar[i]);
    }
    printf("\n");
}


void fill_array(int *ar) {
    for (int i = 0; i < MAXARRAY; i++) {
        ar[i] = rand() % 100;
    }
}

void heapbubble(int pos, int array[], int len) {
    int z = 0;
    int max = 0;
    int tmp = 0;
    int left = 0;
    int right = 0;

    z = pos;

    for (;;) {
        left = 2 * z + 1;
        right = left + 1;

        if (left >= len) {
            return;
        } else if (right >= len) {
            max = left;
        } else if (array[left] > array[right]) {
            max = left;
        } else {
            max = right;
        }

        if (array[z] > array[max]) {
            return;
        }

        tmp = array[z];
        array[z] = array[max];
        array[max] = tmp;
        z = max;
    }
}

void heapsort(int array[], int len) {
    int i = 0;
    int tmp = 0;

    // Build max heap
    for (i = len / 2; i >= 0; --i) {
        heapbubble(i, array, len);
    }
    // Extract elements one by one and restore heap property
    for (i = len - 1; i > 0; i--) {
        tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;
        heapbubble(0, array, i);
    }

}

int main(void) {
    int array[MAXARRAY];
    fill_array(&array[0]);

    printf("Before sort:\n");
    print_array(&array[0]);
    heapsort(&array[0], MAXARRAY);
    printf("After sort:\n");
    print_array(&array[0]);

    return 0;
}