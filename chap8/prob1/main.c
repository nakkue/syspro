#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp = fopen("test.txt", "w");
    if (!fp) {
        perror("file open failed");
        return 1;
    }

    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
        fprintf(fp, "argv[%d]: %s\n", i, argv[i]);
    }

    fclose(fp);
    return 0;
}

