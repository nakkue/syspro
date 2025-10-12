#include <stdio.h>
#include "student.h"

int main(int argc, char *argv[]) {
    struct student rec;
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s FileName\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "w");
    if (fp == NULL) {
        perror("File open error");
        return 1;
    }

    printf("%-9s %-7s %-4s\n", "StudentID", "Name", "Score");

    while (scanf("%d %s %hd", &rec.id, rec.name, &rec.score) == 3) {
        fprintf(fp, "%d %s %hd\n", rec.id, rec.name, rec.score);
    }

    fclose(fp);
    return 0;
}

