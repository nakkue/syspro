#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 512

int main(int argc, char *argv[])
{
    FILE *src, *dst;
    char buf[BUFSIZE];
    size_t n;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s source dest\n", argv[0]);
        return 1;
    }

    src = fopen(argv[1], "r");
    if (src == NULL) {
        perror("open source");
        return 1;
    }

    dst = fopen(argv[2], "w");
    if (dst == NULL) {
        perror("create dest");
        fclose(src);
        return 1;
    }

    while ((n = fread(buf, 1, BUFSIZE, src)) > 0)
        fwrite(buf, 1, n, dst);

    fclose(src);
    fclose(dst);

    printf("Copy done.\n");
    return 0;
}

