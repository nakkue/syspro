#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *d;
    struct stat st;
    char path[1024];
    char *dir;

    if (argc == 1) dir = ".";
    else dir = argv[1];

    if ((dp = opendir(dir)) == NULL) {
        perror("opendir()");
        exit(1);
    }

    while ((d = readdir(dp)) != NULL) {
        sprintf(path, "%s/%s", dir, d->d_name);
        if (lstat(path, &st) < 0) {
            perror("lstat()");
            continue;
        }
        printf("%10ld %s %s", st.st_size, ctime(&st.st_mtime), d->d_name);
    }

    closedir(dp);
    return 0;
}

