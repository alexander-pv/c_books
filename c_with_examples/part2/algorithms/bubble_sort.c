#include <stdio.h>

void bubble_sort(int a[], int size);

void print_arr(int a[], int size);


void print_arr(int a[], int size) {
    for (
            int i = 0;
            i < size;
            i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


void bubble_sort(int a[], int size) {
    int switched = 1;
    int hold = 0;
    int i, j;

    size -= 1;
    for (i = 0; i < size && switched; i++) {
        switched = 0;
        for (j = 0; j < size - i; j++) {
            if (a[j] > a[j + 1]) {
                switched = 1;
                hold = a[j];
                a[j] = a[j + 1];
                a[j + 1] = hold;
            }
        }
    }
}


int main(void) {
    int arr_size = 10;
    int arr[10] = {10, 2, 4, 1, 6, 5, 8, 7, 3, 9};

    printf("Before sort:\n");
    print_arr(arr, arr_size);
    bubble_sort(arr, arr_size);
    printf("After sort:\n");
    print_arr(arr, arr_size);

    return 0;
}
