
#include <stdio.h>

#define MAT_SIZE 100

int mat_mul(int r1, int c1, int c2, int mat1[][MAT_SIZE], int mat2[][MAT_SIZE], int mul[][MAT_SIZE]) {

    int i, j, k;
    // FIll resulting matrix with zero values
    for (i = 0; i < r1; i++) {
        for (j=0; j< c2; j++) {
            mul[i][j] = 0;
        }
    }
    // Multiply
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++) {
                mul[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return 0;
}


int fill_mat(int mat[][MAT_SIZE], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++) {
            printf("Element of mat[%d][%d]", i+1, j+1);
            scanf("%d", &mat[i][j]);

        }
    }
    return 0;
}


int print_mat(int r, int c, int mat[][MAT_SIZE]) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);

            if (j == c - 1) {
                printf("\n");
            }
        }
    }

    return 0;
}

int main(void) {
    int r1, c1, r2, c2, a[MAT_SIZE][MAT_SIZE], b[MAT_SIZE][MAT_SIZE], mul[MAT_SIZE][MAT_SIZE];
    int i, j;

    while (1) {
        printf("\nMat1: Insert the number of rows 1-%d: ", MAT_SIZE);
        scanf("%d", &r1);
        printf("\nMat1: Insert the number of cols 1-%d: ", MAT_SIZE);
        scanf("%d", &c1);
        printf("\nMat2: Insert the number of rows 1-%d: ", MAT_SIZE);
        scanf("%d", &r2);
        printf("\nMat2: Insert the number of cols 1-%d: ", MAT_SIZE);
        scanf("%d", &c2);

        if (c1 != r2) {
            printf("The number of mat1 columns (%d) differs from the number of mat2 rows (%d)", c1, r2);
        }
        else{
            break;
        }
    }
    // Values insertion
    printf("\nInsert the elements of the 1st matrix:\n");
    fill_mat(a, r1, c1);
    printf("Inserted:\n");
    print_mat(r1, c2, a);
    printf("\nInsert the elements of the 2d matrix:\n");
    fill_mat(b, r2, c2);
    printf("Inserted:\n");
    print_mat(r2, c2, b);
    // Matrix multiplication
    mat_mul(r1, c1, c2, a, b, mul);
    printf("The multiplication of 2 mat:\n");
    print_mat(r1, c2, mul);

    return 0;
}