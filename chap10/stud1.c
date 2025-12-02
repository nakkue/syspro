#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    char name[20];
};

int main() {
    struct student *ptr;
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        fprintf(stderr, "Error: invalid number of students.\n");
        exit(1);
    }

    ptr = (struct student *)malloc(n * sizeof(struct student));
    if (ptr == NULL) {
        perror("malloc");
        exit(2);
    }

    printf("Enter ID and name for each student.\n");
    for (i = 0; i < n; i++) {
        scanf("%d %s", &ptr[i].id, ptr[i].name);
    }

    printf("\n* Students (reverse order) *\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%d %s\n", ptr[i].id, ptr[i].name);
    }

    return 0;
}

