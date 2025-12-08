#include <signal.h>

typedef void (*sighandler_t)(int);

sighandler_t my_signal(int signo, sighandler_t handler) {
    struct sigaction newact, oldact;

    newact.sa_handler = handler;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;

    if (sigaction(signo, &newact, &oldact) < 0)
        return SIG_ERR;

    return oldact.sa_handler;
}

