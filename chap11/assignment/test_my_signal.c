#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int);

sighandler_t my_signal(int signo, sighandler_t handler);

void test_handler(int signo) {
    printf("Custom handler: signal %d received\n", signo);
    exit(0);  // ← Ctrl+C 누르면 종료
}

int main() {
    my_signal(SIGINT, test_handler);

    while (1) {
        printf("Press Ctrl-C...\n");
        sleep(1);
    }
}

