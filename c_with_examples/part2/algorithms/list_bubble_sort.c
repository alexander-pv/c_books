#include <stdio.h>
#include <stdlib.h>

#define MAX 10


// List element
typedef struct node {
    struct node *next;
    int *data;
} list_node;

// Add new node to the linked list
void llist_add(list_node **q, int num);

// Perform linked list bubble sort
void llist_bubble_sort(list_node **q);

// Display linked list
void llist_print(list_node **q);

//Add element to a linked list
void llist_add(list_node **q, int num) {
    list_node *tmp;
    tmp = *q;
    //If list is empty, create first node
    if (*q == NULL) {
        *q = malloc(sizeof(list_node));
        tmp = *q;
    } else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }

        // Add node to the end of list
        tmp->next = malloc(sizeof(list_node));
        tmp = tmp->next;

        //Add data to the latest node
        tmp->data = num;
        tmp->next = NULL;
    }

}

void llist_print(list_node **head) {
    list_node *visit;
    visit = *head;

    while (visit != NULL) {
        printf("%d ", (int) visit->data);
        visit = visit->next;
    }
    printf("\n");
}


void llist_bubble_sort(list_node **q) {
    list_node *head = *q;
    list_node *a = NULL;
    list_node *b = NULL;
    list_node *c = NULL;
    list_node *e = NULL;
    list_node *tmp = NULL;

    while (e != head->next) {
        c = a = head;
        b = a->next;
        while (a != e) {
            if (a->data > b->data) {
                if (a == head) {
                    tmp = b->next;
                    b->next = a;
                    a->next = tmp;
                    head = b;
                    c = b;
                } else {
                    tmp = b->next;
                    b->next = a;
                    a->next = tmp;
                    c->next = b;
                    c = b;
                }
            } else {
                c = a;
                a = a->next;
            }
            b = a->next;
            if (b == e) {
                e = a;
            }
        }

    }
}

int main(void) {
    list_node *head = NULL;
    for (int i = 0; i < MAX; i++) {
        llist_add(&head, (rand() % 100));
    }
    printf("Before sort:\n");
    llist_print(&head);
    llist_bubble_sort(&head);
    printf("After sort:\n");
    llist_print(&head);
    return 0;
}