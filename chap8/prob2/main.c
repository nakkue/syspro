#include <stdio.h>
#include <stdlib.h>

int main(void) {
    extern char **environ;
    for (char **p = environ; *p; p++)
        printf("%s\n", *p);
    return 0;
}

