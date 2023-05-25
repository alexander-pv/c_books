#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXARRAY 10

typedef struct tnode {
    int value;
    struct tnode *left;
    struct tnode *right;
} TreeNode;


void fill_array(int *ar);

void print_arr(int ar[], int size);

void insert(TreeNode **p, int value);

void print_tree(TreeNode *root);


void insert(TreeNode **p, int value) {
    if (!*p) {
        *p = (TreeNode *) malloc(sizeof(TreeNode));
        (*p)->left = (*p)->right = NULL;
        (*p)->value = value;
        return;
    }

    if (value < (*p)->value) {
        insert(&(*p)->left, value);
    } else {
        insert(&(*p)->right, value);
    }
}


void print_tree(TreeNode *root) {
    if (root != NULL) {
        print_tree(root->left);
        printf("%d ", root->value);
        print_tree(root->right);
    }
}

void fill_array(int *ar) {
    for (int i = 0; i < MAXARRAY; i++) {
        ar[i] = rand() % 100;
    }
}

void print_arr(int ar[], int size) {
    for (
            int i = 0;
            i < size;
            i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

int main(void) {

    int arr[MAXARRAY];
    fill_array(arr);
    printf("Before sort:\n");
    print_arr(arr, MAXARRAY);

    TreeNode *root = NULL;
    for (int i = 0; i < MAXARRAY; i++) {
        insert(&root, arr[i]);
    }
    printf("After sort:\n");
    print_tree(root);
    return 0;
}