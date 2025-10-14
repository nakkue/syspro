#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char buf[1024];
    int n;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <symlink>\n", argv[0]);
        exit(1);
    }

    n = readlink(argv[1], buf, sizeof(buf) - 1);
    if (n < 0) {
        perror("readlink()");
        exit(1);
    }

    buf[n] = '\0';
    printf("%s\n", buf);
    return 0;
}

