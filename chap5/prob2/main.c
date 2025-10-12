#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    long size;

    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("failed to open file");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fclose(fp);

    printf("file size: %ld bytes\n", size);
    return 0;
}

