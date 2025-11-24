#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pid, status, child;

    pid = fork();
    if (pid == 0) {
        printf("[Child] start pid=%d\n", getpid());
        exit(1);
    }

    child = wait(&status);

    printf("[%d] 자식 %d 종료\n", getpid(), child);
    printf("status = %d\n", status >> 8);

    return 0;
}

