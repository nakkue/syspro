#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd1, fd2;

    fd1 = open("myfile.txt", O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (fd1 < 0) {
        perror("open");
        return 1;
    }

    fd2 = dup(fd1);

    write(fd1, "Hello! Linux\n", 13);
    write(fd2, "Bye! Linux\n", 11);

    close(fd1);
    close(fd2);

    printf("Write complete.\n");
    return 0;
}

