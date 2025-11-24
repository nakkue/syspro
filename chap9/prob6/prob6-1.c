#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Parent PID=%d GID=%d\n", getpid(), getpgrp());

    int pid = fork();
    if (pid == 0) {
        printf("Child PID=%d GID=%d\n", getpid(), getpgrp());
    }

    return 0;
}

