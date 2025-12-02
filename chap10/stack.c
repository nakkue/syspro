#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
        perror("malloc");
        exit(1);
    }
    p->data = data;
    p->next = *top;
    *top = p;
}

int pop(struct node **top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }

    struct node *temp = *top;
    int value = temp->data;

    *top = temp->next;
    free(temp);

    return value;
}

int main() {
    struct node *top = NULL;
    int x;

    printf("Enter natural numbers. Input ends when non-number is entered.\n");

    while (scanf("%d", &x) == 1) {
        push(&top, x);
    }

    printf("\n* Stack elements *\n");
    while (top != NULL) {
        printf("%d ", pop(&top));
    }
    printf("\n");

    return 0;
}

