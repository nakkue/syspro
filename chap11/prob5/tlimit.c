#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int pid;

void alarmHandler() {
    printf("[alarm] child process %d time out\n", pid);
    kill(pid, SIGINT);
}

int main(int argc, char *argv[]) {
    int limit, status;

    signal(SIGALRM, alarmHandler);
    sscanf(argv[1], "%d", &limit);
    alarm(limit);

    pid = fork();
    if (pid == 0) {
        execvp(argv[2], &argv[2]);
        fprintf(stderr, "Cannot execute\n");
    } else {
        wait(&status);
        printf("[parent] child %d exit\n", pid);
    }
}

