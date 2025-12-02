#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node **head, struct node **tail, int data) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
        perror("malloc");
        exit(1);
    }

    p->data = data;
    p->next = NULL;

    if (*tail == NULL) {
        *head = *tail = p;
    } else {
        (*tail)->next = p;
        *tail = p;
    }
}

int delete(struct node **head, struct node **tail) {
    if (*head == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    struct node *temp = *head;
    int value = temp->data;

    *head = temp->next;
    if (*head == NULL)
        *tail = NULL;

    free(temp);
    return value;
}

int main() {
    struct node *head = NULL, *tail = NULL;
    int x;

    printf("Enter natural numbers. Input ends when non-number is entered.\n");

    while (scanf("%d", &x) == 1) {
        addq(&head, &tail, x);
    }

    printf("\n* Queue elements *\n");
    while (head != NULL) {
        printf("%d ", delete(&head, &tail));
    }
    printf("\n");

    return 0;
}

