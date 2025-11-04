#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [-e[NAME] | -u | -g | -i | -p]\n", argv[0]);
        return 1;
    }

    if (strncmp(argv[1], "-e", 2) == 0) {
        if (argv[1][2] == '\0') {
            extern char **environ;
            for (char **p = environ; *p; p++)
                printf("%s\n", *p);
        } else {
            const char *name = argv[1] + 2;
            const char *value = getenv(name);
            if (value) printf("%s=%s\n", name, value);
            else printf("No such environment variable: %s\n", name);
        }
    }
    else if (strcmp(argv[1], "-u") == 0) {
        printf("UID=%d, EUID=%d\n", getuid(), geteuid());
    }
    else if (strcmp(argv[1], "-g") == 0) {
        printf("GID=%d, EGID=%d\n", getgid(), getegid());
    }
    else if (strcmp(argv[1], "-i") == 0) {
        printf("PID=%d\n", getpid());
    }
    else if (strcmp(argv[1], "-p") == 0) {
        printf("PPID=%d\n", getppid());
    }
    else {
        printf("Invalid option\n");
    }

    return 0;
}

