#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[])
{
    struct student rec;
    FILE *fp;
    int id;
    short newscore;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r+b");
    if (fp == NULL) {
        perror("open");
        return 1;
    }

    printf("Enter id to update: ");
    while (scanf("%d", &id) == 1) {
        fseek(fp, (id - 101) * sizeof(rec), SEEK_SET);
        if (fread(&rec, sizeof(rec), 1, fp) == 1) {
            printf("Current score: %d\n", rec.score);
            printf("New score: ");
            scanf("%hd", &newscore);
            rec.score = newscore;
            fseek(fp, -sizeof(rec), SEEK_CUR);
            fwrite(&rec, sizeof(rec), 1, fp);
        } else {
            printf("Record not found.\n");
        }
        printf("Enter id to update (Ctrl+D to end): ");
    }

    fclose(fp);
    return 0;
}

