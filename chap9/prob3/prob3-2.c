#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Parent process start\n");

    if (fork() == 0) {
        execl("/bin/echo", "echo", "hello", NULL);
        exit(1);
    }

    if (fork() == 0) {
        execl("/bin/date", "date", NULL);
        exit(2);
    }

    if (fork() == 0) {
        execl("/bin/ls", "ls", "-l", NULL);
        exit(3);
    }

    printf("Parent process end\n");
    return 0;
}

