
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void test(char *x, char *y, int(*cmp)(const char *, const char *)) {
    printf("Compare strings\n");
    //(*cmp)(x, y) and cmp(x, y) will be correct
    //(*cmp)(x, y) is more informative
    if ((! (*cmp)(x, y)) ) {
        printf("They are equal\n");
    }
    else {
        printf("They are not equal\n");
    }
}


int main(void) {

    char s1[MAX_SIZE], s2[MAX_SIZE];
    // Pointer to a function
    int (*p)(const char *, const char *);
    // Init pointer to a function
    p = &strcmp;
    fgets(s1, MAX_SIZE, stdin);
    fgets(s2, MAX_SIZE, stdin);
    // Call our function
    test(s1, s2, p);

    return 0;
}