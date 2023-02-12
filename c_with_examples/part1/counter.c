
#include <stdio.h>
#include <ctype.h>


// Use Ctrl + D to invoke EOF
int main(void) {

    int tot_chars = 0;
    int tot_lines = 0;
    int tot_words = 0;
    int in_space = 0;
    int c, last = '\n';

    while ( (c = getchar()) != EOF ) {
        last = c;
        tot_chars ++;

        if ( isspace(c) ) {
            in_space = 1;
            if (c == '\n') {
                tot_lines++;
            }
        }
        else {
            tot_words += in_space;
            in_space = 0;
        }
    }

    if ( last != '\n' ) {
        // Учитываем последнюю строку
        tot_lines++;
        tot_words++;
    }

    printf("\nLines: %d words: %d symbols: %d\n", tot_lines, tot_words, tot_chars);
    return 0;
}
