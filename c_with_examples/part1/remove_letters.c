
#include <stdio.h>
#include <string.h>

char *remove_letters(char *string) {

    int i, j = 0;

    for (i = 0; string[i] != '\0'; ++i) {

        if (string[i] >= '0' && string[i] <= '9') {
            // Move digit to a new place
            string[j++] = string[i];
        }
    }
    // Trim string
    string[j] = '\0';

    return string;

}


int main(void) {

    int string_size = 100;
    char buffer[string_size + 1];

    printf("Insert a string: ");


    while (1) {

        // Read from stdin
        fgets(buffer, sizeof(buffer), stdin);

        // Parse line
        if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
            break;
        }

    }

    printf("Parsed: %s\n", buffer);
    remove_letters(buffer);
    printf("After removing letters: %s\n", buffer);

    return 0;
}