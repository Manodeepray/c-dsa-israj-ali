#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct circNode {
    int data;
    struct circNode* next;
};

struct circNode* covertcirl(struct Node* head) {
    if (head == NULL) {
        printf("The input list is empty.\n");
        return NULL;
    }

    struct circNode* circHead = (struct circNode*)malloc(sizeof(struct circNode));
    circHead->data = head->data;
    circHead->next = circHead; 

    struct Node* current = head->next; 
    while (current != NULL) {
        struct circNode* newNode = (struct circNode*)malloc(sizeof(struct circNode));
        newNode->data = current->data;

        newNode->next = circHead->next;
        circHead->next = newNode;

        current = current->next;
    }

    return circHead;
}

void displaycircList(struct circNode* circHead) {
    if (circHead == NULL) {
        printf("The circular list is empty.\n");
        return;
    }

    struct circNode* current = circHead;

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != circHead);

    printf("...\n");
}

void freecircList(struct circNode* circHead) {
    if (circHead == NULL) {
        return;
    }

    struct circNode* current = circHead;
    struct circNode* nextNode;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != circHead);
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;

    struct Node* current = head;
    for (int i = 2; i <= 5; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }

    struct circNode* circHead = covertcirl(head);

    printf("circ Linked List: ");
    displaycircList(circHead);

    freecircList(circHead);

    return 0;
}
