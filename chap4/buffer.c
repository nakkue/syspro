#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <stream>\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "stdin") == 0) {
        fp = stdin;
        printf("Enter one letter: ");
        if (getchar() == EOF) perror("getchar");
    }
    else if (strcmp(argv[1], "stdout") == 0) {
        fp = stdout;
    }
    else if (strcmp(argv[1], "stderr") == 0) {
        fp = stderr;
    }
    else {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("fopen");
            exit(1);
        }
        if (getc(fp) == EOF) perror("getc");
    }

    printf("Stream = %s\n", argv[1]);
    exit(0);
}

