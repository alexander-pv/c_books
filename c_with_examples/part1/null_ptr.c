
#include <stdio.h>
#include <stdlib.h>


int main(void) {

    int *a = NULL;
    unsigned length, i;

    printf("Insert the array length: ");
    scanf("%d", &length);

    if (length > 0) {
        // If memory is allocated, pointer returns
        // If memory is not allocated, NULL returns
        if ( (a = (int *) malloc(length * sizeof(int))) != NULL ) {
            for (i = 0; i< length; i++) {
                a[i] = i * i;
            }
        }
        else {
            printf("Can't allocate memory!");
        }
    }

    if (a != NULL) {
        printf("a = [");
        for (int i = 0; i < length; i++) {
            printf("%d ", *(a + i));
        }
        printf("]\n");
        printf("The variable was initialised. Clearing...\n");
        free(a);
    }
    else{
        printf("The variable was not initialised.\n");
    }


    return 0;
}