#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>

jmp_buf env;

void intHandler() {
    printf("Interrupt\n");
    longjmp(env, 1);
}

int main() {
    signal(SIGINT, intHandler);

    if (setjmp(env) != 0) {
        printf("Return due to interrupt\n");
        exit(0);
    } else {
        printf("First pass\n");
    }

    while (1) {
        printf("Loop\n");
        sleep(1);
    }
}

