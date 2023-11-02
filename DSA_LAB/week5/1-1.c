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
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to traverse the linked list
void traverse(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to check if the list is empty
int isEmpty(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return 1; // List is empty
    } else {
        printf("List is not empty.\n");
        return 0; // List is not empty
    }
}

// Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
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

// Function to insert a node at a specified position
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position should be greater than or equal to 1.\n");
        return head;
    }

    if (position == 1) {
        // Special case: Inserting at the beginning
        return insertAtBeginning(head, data);
    }

    struct Node* newNode = createNode(data);
    struct Node* current = head;
    struct Node* prev = NULL;
    int count = 1;

    while (current != NULL && count < position) {
        prev = current;
        current = current->next;
        count++;
    }

    if (count != position) {
        printf("Invalid position. Position does not exist in the list.\n");
        free(newNode);
        return head;
    }

    prev->next = newNode;
    newNode->next = current;
    return head;
}

// Function to delete a node at the beginning of the list
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node at the end of the list
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
    return head;
}

// Function to delete a node with a given key
struct Node* deleteNodeByKey(struct Node* head, int key) {
    struct Node* current = head;
    struct Node* prev = NULL;

    if (current != NULL && current->data == key) {
        // If the key is found in the head node, delete the head
        head = current->next;
        free(current);
        return head;
    }

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Key not found. Node not deleted.\n");
        return head;
    }

    prev->next = current->next;
    free(current);
    return head;
}

// Function to count the total number of nodes in the list
int countElements(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to search for an element in the linked list
int searchElement(struct Node* head, int key) {
    int position = 1;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            printf("%d found at position %d.\n", key, position);
            return 1; // Element found
        }
        current = current->next;
        position++;
    }
    printf("%d not found in the linked list.\n", key);
    return 0; // Element not found
}

// Function to free memory by deallocating nodes
void freeMemory(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int data, op1, op2, op3, key, position;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Traverse the list\n");
        printf("2. Check if the list is empty\n");
        printf("3. Insert a node\n");
        printf("4. Delete a node\n");
        printf("5. Search for an element\n");
        printf("6. Count the total number of nodes\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op1);

        switch (op1) {
            case 1:
                traverse(head);
                break;
            case 2:
                isEmpty(head);
                break;
            case 3:
                printf("1. Insert at the beginning\n");
                printf("2. Insert at the end\n");
                printf("3. Insert at a specific position\n");
                printf("Enter your choice: ");
                scanf("%d", &op2);

                printf("Enter the data to insert: ");
                scanf("%d", &data);

                if (op2 == 1) {
                    head = insertAtBeginning(head, data);
                } else if (op2 == 2) {
                    head = insertAtEnd(head, data);
                } else if (op2 == 3) {
                    printf("Enter the position to insert: ");
                    scanf("%d", &position);
                    head = insertAtPosition(head, data, position);
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            case 4:
                printf("1. Delete at the beginning\n");
                printf("2. Delete at the end\n");
                printf("3. Delete by key\n");
                printf("Enter your choice: ");
                scanf("%d", &op3);

                if (op3 == 1) {
                    head = deleteAtBeginning(head);
                } else if (op3 == 2) {
                    head = deleteAtEnd(head);
                } else if (op3 == 3) {
                    printf("Enter the key to delete: ");
                    scanf("%d", &key);
                    head = deleteNodeByKey(head, key);
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            case 5:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                searchElement(head, key);
                break;
            case 6:
                printf("Total number of nodes: %d\n", countElements(head));
                break;
            case 7:
                freeMemory(head);
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
