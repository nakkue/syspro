#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[]) {
    int fd, id;
    struct student record;

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
        off_t offset = (off_t)(id - START_ID) * sizeof(record);
        lseek(fd, offset, SEEK_SET);

        if (lockf(fd, F_LOCK, sizeof(record)) == -1) {
            perror("lockf F_LOCK");
            exit(3);
        }

        if (read(fd, &record, sizeof(record)) > 0 && record.id != 0) {
            printf("Name: %s\tStuID: %d\tScore: %d\n", record.name, record.id, record.score);
            printf("Enter new score: ");
            scanf("%d", &record.score);
            lseek(fd, -(off_t)sizeof(record), SEEK_CUR);
            write(fd, &record, sizeof(record));
        } else {
            printf("No record with StudentID %d\n", id);
        }

        lseek(fd, offset, SEEK_SET);
        lockf(fd, F_ULOCK, sizeof(record));

        printf("\nEnter StudentID you want to modify: ");
    }

    close(fd);
    return 0;
}

