#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Maximum number of elements

struct lnode {
    int number;
    struct lnode *next;
};

// Add node to the beginning of the list
void llist_add_begin(struct lnode **n, int val);
// Reverse linked list
void llist_reverse(struct lnode **n);
// Display linked list
void llist_display(struct lnode *n);


int main(void) {

    struct lnode *new = NULL;
    int i = 0;

    // Insert numbers to a linked list: 0-10
    for (i = 0; i <=MAX; i++) {
        llist_add_begin(&new, i);
    }

    printf("Initial linked list: ");
    llist_display(new);
    llist_reverse(&new);
    printf("Reversed linked list");
    llist_display(new);

    return 0;
}

void llist_add_begin(struct lnode **n, int val) {
    struct lnode *temp = NULL;
    temp = malloc(sizeof(struct lnode));
    temp->number = val;
    temp->next = *n;
    *n = temp;
}

void llist_reverse(struct lnode **n) {
    struct lnode *a = NULL;
    struct lnode *b = NULL;
    struct lnode *c = NULL;
    a = *n;
    b = NULL;

    while (a != NULL) {
        c = b;
        b = a;
        a = a->next;
        b->next = c;
    }
    *n = b;
}

void llist_display(struct lnode *n) {
    while ( n != NULL) {
        printf(" %d", n->number);
        n = n->next;
    }
    printf("\n");
}
