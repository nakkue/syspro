#include <sys/types.h>
#include <sys/stat.h>
#include <utime.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct stat buf;
    struct utimbuf time;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <target>\n", argv[0]);
        exit(1);
    }

    if (stat(argv[1], &buf) < 0) {
        perror("stat()");
        exit(1);
    }

    time.actime = buf.st_atime;
    time.modtime = buf.st_mtime;

    if (utime(argv[2], &time) < 0) {
        perror("utime()");
        exit(1);
    }
    return 0;
}

