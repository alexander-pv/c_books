
#include <stdio.h>

int main(void) {

    int intType;
    float floatType;
    double doubleType;
    char charType;

    printf("Size of int: %ld byte\n", sizeof(intType));
    printf("Size of float: %ld byte\n", sizeof(floatType));
    printf("Size of double: %ld byte\n", sizeof(doubleType));
    printf("Size of char: %ld byte\n", sizeof(charType));

    return 0;
}