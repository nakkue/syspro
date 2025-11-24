#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pid1, pid2, child, status;

    pid1 = fork();
    if (pid1 == 0) {
        sleep(1);
        exit(1);
    }

    pid2 = fork();
    if (pid2 == 0) {
        sleep(2);
        exit(2);
    }

    child = wait(&status);
    printf("first finished: %d, status=%d\n", child, status >> 8);

    child = wait(&status);
    printf("second finished: %d, status=%d\n", child, status >> 8);

    return 0;
}

