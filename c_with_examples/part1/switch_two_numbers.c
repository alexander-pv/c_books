
#include <stdio.h>

int main(void) {

    double a, b;
    printf("Insert A: ");
    scanf("%lf", &a);
    printf("Insert B: ");
    scanf("%lf", &b);

    // We do not use temp variable to change values
    // Only 3 arithmetic ops
    a = a - b;
    b = a + b;
    a = b - a;

    printf("After switch, A = %.2lf\n", a);
    printf("After switch, B = %.2lf\n", b);

    return 0;
}