#include <stdio.h>
#include <string.h>

static int binsearch(char *str[], int max, char *value);

static int binsearch(char *str[], int max, char *value) {
    int position;
    int begin = 0;
    int end = max;
    int cond = 0;

    while (begin < end) {
        position = (begin + end) / 2;
        if ((cond = strcmp(str[position], value)) == 0) {
            return position;
        } else if (cond < 0) {
            begin = position + 1;
        } else {
            end = position - 1;
        }
    }

    return 0;
}

int main(void) {

    // Array of strings must be sorted
    char *strings[] = {"audi", "bentley", "bmw", "cadillac", "ford"};
    int i, asize, result;
    i = asize = result = 0;

    asize = sizeof(strings) / sizeof(strings[0]);

    for (i = 0; i < asize; i++) {
        printf("%d: %s\n", i, strings[i]);
    }
    printf("\n");

    if ((result = binsearch(strings, asize, "bmw")) != 0) {
        printf("`bmw` was found, position: %d\n", result);
    } else {
        printf("`bmw` was not found\n");
    }

    if ((result = binsearch(strings, asize, "mersedes")) != 0) {
        printf("`mersedes` was found, position: %d\n", result);
    } else {
        printf("`mersedes` was not found\n");
    }

    return 0;
}