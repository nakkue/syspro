#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pid, status;

    pid = fork();
    if (pid == 0) {
        execvp(argv[1], &argv[1]);
        fprintf(stderr, "exec failed\n");
        exit(1);
    }

    wait(&status);
    printf("Child exit code = %d\n", status >> 8);

    return 0;
}

