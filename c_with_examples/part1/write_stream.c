
#include <stdio.h>
#include <string.h>

int main (int argc, char **argv) {

    int i, ch;
    FILE *f[5];

    if (argc < 3 || argc > 7) {
        puts("Incorrect number of params");
        return 1;
    }
    if  ( strcmp(argv[1], "-w") !=0  && strcmp(argv[1], "-a") !=0 ) {
        puts("First parameter must be `-w` or `-a`");
        return 2;
    }
    for (i = 0; i < argc - 2; i++) {
        f[i] = fopen(argv[i + 2], argv[1] + 1);
        if (f[i] == NULL) {
            printf("Can't open file %s\n", argv[i + 2]);
            return 3;
        }

    }
    // Work until EOF - Ctrl+D
    while ( (ch = getchar()) != EOF ) {
        for (i = 0; i < argc - 2; i++) {
            putc(ch, f[i]);
        }
    }
    //Close files and write data
    for (i = 0; i < argc - 2; i++) {
        fclose(f[i]);
    }

    return 0;
}


