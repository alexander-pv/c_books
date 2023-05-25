#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAXARRAY 10


int main(void) {

    int array[MAXARRAY] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    int left = 0;
    int right = MAXARRAY - 1;
    int mid;
    int number;
    int bsearch = FALSE;

    printf("Array:\n");
    for (int i = 0; i < MAXARRAY; i++) {
        printf("[%d]", array[i]);
    }
    printf("\nInsert element for search: ");
    scanf("%d", &number);

    while (bsearch == FALSE && left <= right) {
        mid = (left + right) / 2;

        if (number == array[mid]) {
            bsearch = TRUE;
            printf("Found number. Index: %d\n", mid);
        } else {
            if (number < array[mid]) {
                right = mid - 1;
            }
            if (number > array[mid]) {
                left = mid + 1;
            }
        }
    }
    if (bsearch == FALSE) {
        printf("Number is not found\n");
    }

    return 0;
}
