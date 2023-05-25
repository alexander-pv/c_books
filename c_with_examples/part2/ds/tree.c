#include <stdio.h>
#include <stdlib.h>


struct tnode {
    int field;
    struct tnode *left;
    struct tnode *right;
};


// Pre-order tree traversal (from upper level to lower)
void pre_order_tree_print(tnode *tree) {
    if (tree != NULL) {
        printf("%d", tree->field);
        tree_print(tree->left);
        tree_print(tree->right);
    }
}


// In-order tree traversal (from left to right)
void in_order_tree_print(tnode *tree) {
    if (tree != NULL) {
        tree_print(tree->left);
        printf("%d", tree->field);
        tree_print(tree->right);
    }
}


// Post-order tree traversal (from lower level to upper)
void post_order_tree_print(tnode *tree) {
    if (tree != NULL) {
        tree_print(tree->left);
        tree_print(tree->right);
        printf("%d", tree->field);
    }
}


struct tnode *add_node(int x, struct tnode *tree) {
    if (tree == NULL) {
        tree = (struct tnode *) malloc(sizeof(struct tnode));
        tree->field = x;
        tree->left = NULL;
        tree->right = NULL;
    }
    else if (x < tree->field) {
        tree->left = add_node(x, tree->left);
    }
    else {
        tree->right = add_node(x, tree->right);
    }
    return tree;
}


void free_mem(struct tnode *tree) {
    if (tree != NULL) {
        free_mem(tree->left);
        free_mem(tree->right);
        free(tree);
    }
}