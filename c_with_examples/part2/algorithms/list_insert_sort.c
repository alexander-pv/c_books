#include <stdio.h>
#include <stdlib.h>


struct node {
    int number;
    struct node *next;
};


struct node *insert_node(struct node *head, int value) {

    struct node *temp = NULL;
    struct node *one = NULL;
    struct node *two = NULL;

    // Empty list
    if (head->number == -1) {
        head->number = value;
        return head;
    }

    one = head;
    two = head->next;

    temp = (struct node *) malloc(sizeof(struct node *));
    temp->number = value;

    while (two != NULL && temp->number < two->number) {
        one = one->next;
        two = two->next;
    }

    if (value > one->number) {
        head = temp;
        head->next = one;
        one->next = two;
    } else {
        one->next = temp;
        temp->next = two;
    }

    return head;

}


int main(void) {
    struct node *head = (struct node *) malloc(sizeof(struct node *));
    head->number = -1;
    head->next = NULL;

    struct node *current = NULL;
    struct node *next = NULL;
    int test[] = {8, 3, 2, 6, 1, 5, 4, 7, 9, 0};
    int i;

    for (i = 0; i < 10; i++) {
        head = insert_node(head, test[i]);
    }
    printf(" Before  After\n");
    i = 0;
    while (head != NULL) {
        printf("%4d\t%4d\n", test[i++], head->number);
        head = head->next;
    }

    for (current = head; current != NULL; current = next) {
        next = current->next;
        free(current);
    }
}