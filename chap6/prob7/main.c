#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <link>\n", argv[0]);
        exit(1);
    }

    if (unlink(argv[1]) == -1) {
        perror("unlink()");
        exit(1);
    }
    return 0;
}

