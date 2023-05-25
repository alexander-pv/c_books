#include <stdio.h>
#include <stdlib.h>


// List element
typedef struct list_node {
    struct list_node *next;
    void *data;
} list_node_t;


// Singly-linked list
typedef struct list {
    int size;
    list_node_t *head;
    list_node_t *tail;
} list_t;


// Initialize linked list
list_t *create_list(void) {
    list_t *lt = malloc(sizeof(list_t));
    lt->size = 0;
    lt->head = NULL;
    lt->tail = lt->head;
    return lt;
}


// Add an element to the beginning of a list
void list_push(list_t *lt, void *data) {
    list_node_t *node = malloc(sizeof(list_node_t));
    node->data = data;

    node->next = lt->head;
    lt->head = node;
    lt->size += 1;
}

// Add an element to the end of a list
void list_push_back(list_t *lt, void *data) {
    list_node_t *node = malloc(sizeof(list_node_t));
    node->data = data;

    // Check whether a list is empty or not
    if (lt->tail != NULL){
        lt->tail->next = node;
    }
    else {
        lt.head = node;
    }

    lt->tail = node;
    lt->size += 1;

}

// Extract first element from a list
void *list_pop(list_t *lt) {
    if (lt->size == 0) {
        return NULL;
    }

    list_node_t *node = lt->head;
    void *ret_val = node->data;

    lt->size -= 1;
    lt->head = node->next;

    free(node);

    if (lt->size == 0) {
        // It was last element
        lt->head = NULL;
        lt->tail = NULL;
    }
    return ret_val;
}

