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

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to display the linked list in reverse order
void displayReverse(struct Node* head) {
    if (head == NULL) {
        return; // Base case: If the list is empty, return
    }
    
    // Recursively display the rest of the list in reverse order
    displayReverse(head->next);
    
    // Print the current node's data
    printf("%d -> ", head->data);
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

    printf("Linked List : \n");
    display(head);
    // Display the linked list in reverse order
    printf("Linked List in Reverse Order:\n ");
    displayReverse(head);
    printf("NULL\n");

    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
