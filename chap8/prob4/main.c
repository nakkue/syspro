#include <stdio.h>
#include <stdlib.h>

static void handler1(void) { printf("First exit handler\n"); }
static void handler2(void) { printf("Second exit handler\n"); }

int main(void) {
    atexit(handler1);
    atexit(handler2);
    printf("Main end\n");
    return 0;
}

