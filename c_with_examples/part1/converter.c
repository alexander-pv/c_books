// gcc converter.c -o converter -lm
#include <stdio.h>
#include <math.h>

int conv_binary_to_dec(long long n);
long long conv_dec_to_binary(int n);


int main(void) {
    long long n;
    printf("Insert binary number: ");
    scanf("%lld", &n);
    printf("%lld (binary) = %d (decimal)\n", n, conv_binary_to_dec(n));

    printf("Insert decimal number: ");
    scanf("%d", &n);
    printf("%d (decimal) = %lld (binary)\n", n, conv_dec_to_binary(n));

    return 0;
}

int conv_binary_to_dec(long long n) {
    int remainder, i = 0, dec_num = 0;
    while (n !=0 ){
        remainder = n % 10;
        n /= 10;
        dec_num += remainder * pow(2, i);
        ++i;
    }
    return dec_num;
}


long long conv_dec_to_binary(int n) {
    long long binary_num = 0;
    int remainder, i = 1;

    while (n != 0) {
        remainder = n % 2;
        n /= 2;
        binary_num += remainder * i;
        i *= 10;
    }
    return binary_num;
}