
#include <stdio.h>
#include <stdlib.h>

#define NB_ENABLE 0x01
#define NB_DISABLE 0x00

int getch(void) {
    return fgetc(stdin);
}

// Read every key from keyboard
void change_direction() {
    // Use getch to read every key passed
    char symbol;
    int change_x, change_y;
    symbol = getch();
    // Use W,A,S,D to change direction
    switch (symbol) {
        case 'w':
            if (change_x != 1 || change_y != 0) {
                change_x = -1;
                change_y = 0;
                printf("Passed w. change_x: %d change_y: %d\n", change_x, change_y);
            }
            break;
        case 'a':
            if (change_x != 0 || change_y != 1) {
                change_x = 0;
                change_y = -1;
                printf("\nPassed a. change_x: %d change_y: %d\n", change_x, change_y);
            }
            break;
        case 's':
            if (change_x != -1 || change_y != 0) {
                change_x = 1;
                change_y = 0;
                printf("\nPassed s. change_x: %d change_y: %d\n", change_x, change_y);
            }
            break;
        case 'd':
            if (change_x != 0 || change_y != -1) {
                change_x = 0;
                change_y = 1;
                printf("\nPassed d. change_x: %d change_y: %d\n", change_x, change_y);
            }
            break;
#ifndef WINDOWS
        case 'q':
            exit(0);
#endif
        default:
            break;
    }

}


int main(void) {
    change_direction();
    return 0;
}
