#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[])
{
    struct student rec;
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("open");
        return 1;
    }

    printf("ID   Name   Score\n");
    while (fread(&rec, sizeof(rec), 1, fp) == 1)
        printf("%d %s %d\n", rec.id, rec.name, rec.score);

    fclose(fp);
    return 0;
}

