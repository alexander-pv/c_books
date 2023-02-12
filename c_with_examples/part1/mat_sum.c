
#include <stdio.h>

#define MAT_SIZE 100

int mat_sum(int r, int c, int mat1[][MAT_SIZE], int mat2[][MAT_SIZE], int sum[][MAT_SIZE]) {

    int i, j;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
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
    int r, c, a[MAT_SIZE][MAT_SIZE], b[MAT_SIZE][MAT_SIZE], sum[MAT_SIZE][MAT_SIZE];
    int i, j;

    printf("\nInsert the number of rows 1-%d: ", MAT_SIZE);
    scanf("%d", &r);
    printf("\nInsert the number of cols 1-%d: ", MAT_SIZE);
    scanf("%d", &c);

    printf("\nInsert the elements of the 1st matrix:\n");
    fill_mat(a, r, c);
    printf("\nInsert the elements of the 2d matrix:\n");
    fill_mat(b, r, c);

    mat_sum(r, c, a, b, sum);
    printf("The sum of 2 mat:\n");
    print_mat(r, c, sum);

    return 0;
}