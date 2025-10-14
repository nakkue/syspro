#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct stat buf;
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ...\n", argv[0]);
        exit(1);
    }

    for (i = 1; i < argc; i++) {
        printf("%s: ", argv[i]);
        if (lstat(argv[i], &buf) < 0) {
            perror("lstat()");
            continue;
        }

        if (S_ISREG(buf.st_mode)) printf("regular file\n");
        else if (S_ISDIR(buf.st_mode)) printf("directory\n");
        else if (S_ISCHR(buf.st_mode)) printf("character device\n");
        else if (S_ISBLK(buf.st_mode)) printf("block device\n");
        else if (S_ISFIFO(buf.st_mode)) printf("FIFO\n");
        else if (S_ISLNK(buf.st_mode)) printf("symbolic link\n");
        else if (S_ISSOCK(buf.st_mode)) printf("socket\n");
        else printf("unknown type\n");
    }
    return 0;
}

