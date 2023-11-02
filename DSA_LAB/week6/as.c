#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void insert(struct node **head, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head);
    new_node->prev = NULL;

    if ((*head) != NULL) {
        (*head)->prev = new_node;
    }

    (*head) = new_node;
}

void print_list(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node *head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);

    printf("Doubly linked list: ");
    print_list(head);

    return 0;
}
