
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TO_READ 10
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top;


// Check whether a stack is empty
int is_empty(void){
    if (top < 0) {
        printf("The stack is empty!\n");
        return 1;
    }
    return 0;
}

// Push value to a stack
void push(int x) {
    if (top >= MAX_SIZE) {
        printf("The stack is full!\n");
        return;
    }
    stack[top] = x;
    top++;
}

// Wrapper for stdin stack push
void push_from_stdin(void) {

    char stdin_num[MAX_SIZE];
    char *ptr;
    int num;
    printf("Insert value and press Enter: ");
    for (;;) {
        fgets(stdin_num, MAX_SIZE, stdin);
        num = strtol(stdin_num, &ptr, 10);
        if (ptr != stdin_num) {
            break;
        }
        else{
            printf("Can not convert: %s\nInsert valid value:\n", stdin_num);
        }

    }
    push(num);
}

// Pop value from a stack
int pop(void) {
    int popped;
    top--;
    if (is_empty()) {
        return 0;
    }
    popped = stack[top];
    printf("Popped: %d\n", popped);
    return popped;
}

// Display stack
void display(void) {
    if (is_empty() == 0) {
        int i;
        printf("Current stack:\n");
        for (i = 0; i < top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}


int main(void) {

    char command[MAX_TO_READ];
    for (;;) {
        printf("Stack commands: P - push, G - pop, D - display stack, Q - exit: \n");
        fgets(command, MAX_TO_READ, stdin);
        *command = toupper(*command);
        if (strlen(command) == 2) {
            switch (*command) {
                case 'P':
                    push_from_stdin();
                    break;
                case 'G':
                    pop();
                    break;
                case 'D':
                    display();
                    break;
                case 'Q':
                    printf("Exiting...\n");
                    return 0;
            }
        }
    }

}
