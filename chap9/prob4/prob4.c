#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int mysystem(const char *cmd) {
    int pid, status;

    if (cmd == NULL)
        return 1;

    pid = fork();
    if (pid < 0)
        return -1;

    if (pid == 0) {
        execl("/bin/sh", "sh", "-c", cmd, NULL);
        exit(127);
    }

    wait(&status);
    return status;
}

int main() {
    int status;

    status = mysystem("date");
    printf("Exit code = %d\n", WEXITSTATUS(status));

    status = mysystem("hello");
    printf("Exit code = %d\n", WEXITSTATUS(status));

    status = mysystem("who; exit 44");
    printf("Exit code = %d\n", WEXITSTATUS(status));

    return 0;
}

