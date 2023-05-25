#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int number;
    struct node *next;
} ListNode;

ListNode *addnode(int number, ListNode *next);

ListNode *mergesort(ListNode *head);

ListNode *merge(ListNode *head_left, ListNode *head_right);

void print_list(ListNode *head);

void free_list(ListNode *head);


void print_list(ListNode *head) {
    ListNode *current;
    for (current = head; current != NULL; current = current->next) {
        printf(" %d ", current->number);
    }
    printf("\n");
}

void free_list(ListNode *head) {
    ListNode *current;
    ListNode *next;
    for (current = head; current != NULL; current = next) {
        next = current->next;
        free(current);
    }
}


ListNode *addnode(int number, ListNode *head) {
    ListNode *tnode;
    tnode = (ListNode *) malloc(sizeof(*tnode));
    if (tnode != NULL) {
        tnode->number = number;
        tnode->next = head;
    }
    return tnode;
}


ListNode *mergesort(ListNode *head) {
    ListNode *head_left;
    ListNode *head_right;

    // Recursion base
    if ((head == NULL) || (head->next == NULL)) {
        return head;
    }

    head_left = head;
    head_right = head->next;

    while ((head_right != NULL) && (head_right->next != NULL)) {
        head = head->next;
        head_right = head->next->next;
    }

    head_right = head->next;
    head->next = NULL;

    return merge(mergesort(head_left), mergesort(head_right));
}

ListNode *merge(ListNode *head_left, ListNode *head_right) {
    ListNode *head_new;

    if (head_left == NULL) {
        return head_right;
    }

    if (head_right == NULL) {
        return head_left;
    }

    if (head_left->number < head_right->number) {
        head_new = head_left;
        head_new->next = merge(head_left->next, head_right);
    } else {
        head_new = head_right;
        head_new->next = merge(head_left, head_right->next);

    }
    return head_new;

}


int main(void) {
    ListNode *head = (ListNode *) malloc(sizeof(*head));
    int test[] = {8, 3, 2, 6, 1, 0, 5, 4, 7, 9};
    int i;

    for (i = 0; i < 10; i++) {
        head = addnode(test[i], head);
    }

    printf("Before:\n");
    print_list(head);
    head = mergesort(head);
    printf("After:\n");
    print_list(head);
    free_list(head);

    return 0;
}