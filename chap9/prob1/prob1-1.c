#include <stdio.h>
#include <unistd.h>

int main() {
    int pid;
    printf("[PARENT] pid = %d\n", getpid());

    pid = fork();

    printf("[%d] return = %d\n", getpid(), pid);
    return 0;
}

