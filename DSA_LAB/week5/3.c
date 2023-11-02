#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit program if memory allocation fails
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to print the mth node from the end
void printMthFromEnd(struct Node* head, int m) {
    if (head == NULL || m <= 0) {
        printf("Invalid input.\n");
        return;
    }   

    struct Node* mainPtr = head;
    struct Node* refPtr = head;

    // Move refPtr m nodes ahead
    for (int i = 0; i < m; i++) {
        if (refPtr == NULL) {
            printf("The list has less than %d nodes.\n", m);
            return;
        }
        refPtr = refPtr->next;
    }

    // Move both pointers until refPtr reaches the end
    while (refPtr != NULL) {
        mainPtr = mainPtr->next;
        refPtr = refPtr->next;
    }

    // mainPtr now points to the mth node from the end
    printf("The %dth node from the end is: %d\n", m, mainPtr->data);
}

int main() {
    struct Node* head = NULL;
    int data, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }

    printf("Enter the value of m: ");
    int m;
    scanf("%d", &m);

    // Print the mth node from the end
    printMthFromEnd(head, m);

    // Free memory by deallocating nodes when done
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}