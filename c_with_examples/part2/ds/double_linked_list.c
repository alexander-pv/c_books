#include <stdio.h>
#include <stdlib.h>


struct dl_list {
    int field;
    struct dl_list *next;
    struct dl_list *prev;
};

// Initialize double linked list
struct dl_list *init(int a) {
    struct dl_list *lst;
    lst = (struct dl_list *) malloc(sizeof(struct dl_list));
    lst->field = a;
    lst->next = NULL;
    lst->prev = NULL;
    return lst;
}


struct dl_list *add_node(struct dl_list *lst, int number) {
    struct dl_list *temp, *p;
    temp = (struct dl_list *) malloc(sizeof(struct dl_list));
    p = lst->next;
    lst->next = temp;
    temp->field = number;
    temp->next = p;
    if (p != NULL) {
        p->prev = temp;
    }
    return temp;
}

struct dl_list *delete_node(struct dl_list *lst) {
    struct dl_list *prev, *next;
    prev = lst->prev;
    next = lst->next;
    if (prev != NULL) {
        prev->next = lst->next;
    }
    if (next != NULL) {
        next->prev = lst->prev;
    }
    free(lst);
    return prev;
}

struct dl_list *delete_head(struct dl_list *root) {
    struct dl_list *temp;
    temp = root->next;
    temp->prev = NULL;
    free(root);
    return temp;
}

void display_list(struct dl_list *lst) {
    struct dl_list *p;
    p = lst;
    do {
        printf("%d ", p->field);
        p = p->next;
    } while (p != NULL);
}

void display_reverse_list(struct dl_list *lst) {
    struct dl_list *p;
    p = lst;
    while (p->next != NULL) {
        p = p->next;
    }
    do {
        printf("%d ", p->field);
        p = p->prev;
    } while (p != NULL);
}

struct dl_list *swap(struct dl_list *lst1, struct dl_list *lst2, struct dl_list *head) {
    // Return new dl_list root
    struct dl_list *prev1, *prev2, *next1, *next2;
    prev1 = lst1->prev;
    prev2 = lst2->prev;
    next1 = lst1->next;
    next2 = lst2->next;

    if (lst2 == next1) {
        lst2->next = lst1;
        lst2->prev = prev1;
        lst1->next = next2;
        lst1->prev = lst2;

        if (next2 != NULL) {
            next2->prev = lst1;
        }
        if (lst1 != head) {
            prev1->next = lst2;
        }
    } else if (lst1 == next2) {
        lst1->next = lst2;
        lst1->prev = prev2;
        lst2->next = next1;
        lst2->prev = lst1;
        if (next1 != NULL) {
            next1->prev = lst2;
        }
        if (lst2 != head) {
            prev2->next = lst1;
        }
    } else {
        if (lst1 != head) {
            prev1->next = lst2;
        }
        lst2->next = next1;
        if (lst2 != head) {
            prev2->next = lst1;
        }
        lst1->next = next2;
        lst2->prev = prev1;
    }
    if (lst1 == head) {
        return lst2;
    }
    if (lst2 == head) {
        return lst1;
    }
    return head;

}

int main(void) {

    struct dl_list *head, *cur;
    int num;
    printf("a = ");
    scanf("%d", &num);
    head = init(num);
    cur = head;
    for (int i; i < 5; i++) {
        printf("a = ");
        scanf("%d", &num);
        cur = add_node(cur, num);
    }
    printf("\nInitial list: \n");
    display_list(head);

    // Swap 1 and 2 elements
    printf("\nSwap [1] and [2]: \n");
    cur = head->next;
    head = swap(head, cur, head);
    display_list(head);

    // Delete 3d list element
    printf("\nDelete [3]: \n");
    cur = head->next->next;
    delete_node(cur);
    display_list(head);

    return 0;
}