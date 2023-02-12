
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Queue max size
#define MAX 100
#define MAX_TO_READ 10

int in_pos;       // Index of the next free place for an element
int out_pos;      // Index of the next queue element to get
char *queue[MAX]; // Store elements of queue here


void put(char *q) {
    // Put an element into a queue
    if (in_pos == MAX){
        printf("The queue is full!\n");
        return;
    }
    queue[in_pos] = q;
    in_pos++;
}

char *get(void) {
    // Get an element from a queue
    if (in_pos == out_pos) {
        printf("The queue is empty!\n");
        return '\0';
    }
    out_pos++;
    return queue[out_pos - 1];

}

void remove_el(void) {
    char *p;
    if ( (p=get()) == NULL) {
        return;
    }
    printf("Removed from the queue: %s\n", p);
}

void new_el(void) {
   char s[MAX], *p;

   printf("Insert string to input to a Queue: \n");
   fgets(s, MAX_TO_READ, stdin);
   if (*s == 0) {
       return;
   }
   p = (char *)malloc(strlen(s) + 1);
   if (!p) {
       printf("No memory!");
       return;
   }
   strcpy(p, s);
   if (*s) {
       put(p);
   }

}

void display() {
    register int j;
    for (j = out_pos; j< in_pos; j++) {
        printf("%d. %s", j+1, queue[j]);
    }
}

int main(void) {

    char s[MAX_TO_READ];
    register int j;

    //Init array with empty pointers
    for (j = 0; j < MAX; j++) {
        queue[j] = NULL;
    }

    for (;;) {
        printf("I - insert, D - display, R - remove, Q - exit: ");
        fgets(s, MAX_TO_READ, stdin);
        *s = toupper(*s);
        switch (*s) {
            case 'I':
                new_el();
                break;
            case 'D':
                display();
                break;
            case 'R':
                remove_el(); break;
            case 'Q':
                printf("Exiting...\n");
                return 0;
        }
    }
}
