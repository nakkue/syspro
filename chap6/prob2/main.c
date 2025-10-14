#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <mode> <filename>\n", argv[0]);
        exit(1);
    }

    int newmode = (int)strtol(argv[1], NULL, 8);
    if (chmod(argv[2], newmode) == -1) {
        perror("chmod()");
        exit(1);
    }
    return 0;
}

