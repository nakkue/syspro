#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

void p1();
void p2();

int main() {
    if (setjmp(env) != 0) {
        printf("Exception handling after return due to error\n");
        exit(0);
    } else {
        printf("First pass\n");
    }
    p1();
}

void p1() { p2(); }

void p2() {
    printf("Error\n");
    longjmp(env, 1);
}

