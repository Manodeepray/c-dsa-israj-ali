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
void isEmpty(struct Node* head) {
    if (head == NULL){
        printf("list is empty");
      

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
    // Implement this function based on your requirements
    // Remember to handle cases where position is 0 or greater than the list length
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
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    if (position < 1) {
        printf("Invalid position. Position should be greater than or equal to 1.\n");
        return head;
    }

    if (position == 1) {
        // Special case: Deleting the first node
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    int count = 1;

    while (current != NULL && count < position) {
        prev = current;
        current = current->next;
        count++;
    }

    if (count != position || current == NULL) {
        printf("Invalid position. Position does not exist in the list.\n");
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

int searchElement(struct Node* head, int key) {
    int position = 1;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; // Element not found
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
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

    printf("Linked List Contents: ");
    display(head);

    // Free memory by deallocating nodes when done
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    int op1,op2,op3,key,i;
   printf("1) traverse the list : \n");
        printf("2) Check if the list is empty. :\n");
        printf("3) Insert a node at the certain position :\n");
        printf("4) Delete a node at the certain position : \n");
        printf("5) Delete a node for the given key :\n");
        printf("6) Count the total number of nodes. :\n");
        printf("7) Search for an element in the linked list. :\n");
        printf("8) exit  :\n");
        scanf("%d",&op1);


        switch (op1)
        {
        case 1:
            traverse(head);
            break;
        case 2:
            isEmpty(head);
            break;
        case 3:
            printf("1) at beginning \n 2) end \n 3) any position\n ");
            
            scanf("%d",&op2);
            switch (op2)
            {
            case 1:
                insertAtBeginning(head,data);
                break;
            case 2:
                insertAtEnd(head,data);
                break;
            case 3:
                printf("enter the position : \n");
                int position;
                scanf("%d",&position);

                insertAtPosition(head,data,position);
                break;    
            
            default: 
                printf("not in option \n");
                break;
            };
            break;
        case 4 :
            printf("1) at beginning \n 2) end \n 3) any position\n ")
            
            scanf("%d",&op3);
            switch (op3)
            {
            case 1:
                deleteAtBeginning(head);
                break;
            case 2:
                deleteAtEnd(head);
                break;
            case 3:
                printf("enter the position : \n");
                int position;
                scanf("%d",&position);

                deleteAtPosition(head,position);
                break;    
            
            default: 
                printf("not in option \n");
                break;
            };
            break;
        case 5 :
            printf("dont know \n");
            break;
        case 6:
                countElements(head);
            break;
        case 7:
            printf("enter the element to search :\n");
            scanf("%d",&key);
            searchElement(head,key);
            break;
        case 8:
            i=0;
            break;
        default:
            printf("not in option \n");
            break;
        }
    

    return 0;
}
