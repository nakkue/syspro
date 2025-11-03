#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[]) {
    int fd, id;
    struct student record;
    struct flock lock;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(1);
    }
    if ((fd = open(argv[1], O_RDWR)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    printf("\nEnter StudentID you want to modify: ");
    while (scanf("%d", &id) == 1) {
        lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = (off_t)(id - START_ID) * (off_t)sizeof(record);
        lock.l_len = (off_t)sizeof(record);

        if (fcntl(fd, F_SETLKW, &lock) == -1) {
            perror("fcntl F_WRLCK");
            exit(3);
        }

        lseek(fd, lock.l_start, SEEK_SET);
        if (read(fd, &record, sizeof(record)) > 0 && record.id != 0) {
            printf("Name: %s\tStuID: %d\tScore: %d\n", record.name, record.id, record.score);
            printf("Enter new score: ");
            scanf("%d", &record.score);
            lseek(fd, -(off_t)sizeof(record), SEEK_CUR);
            write(fd, &record, sizeof(record));
        } else {
            printf("No record with StudentID %d\n", id);
        }

        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);

        printf("\nEnter StudentID you want to modify: ");
    }

    close(fd);
    return 0;
}

