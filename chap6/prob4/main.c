#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *d;
    char *dir;

    if (argc == 1) dir = ".";
    else dir = argv[1];

    if ((dp = opendir(dir)) == NULL) {
        perror("opendir()");
        exit(1);
    }

    while ((d = readdir(dp)) != NULL)
        printf("%s\n", d->d_name);

    closedir(dp);
    return 0;
}

