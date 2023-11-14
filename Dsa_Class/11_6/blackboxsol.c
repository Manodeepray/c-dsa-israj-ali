#include <stdio.h>
#include <stdlib.h>

// A Linked List Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// A Circular Queue with an additional field to store head and tail pointers
typedef struct CircularQueue {
    Node* head;
    Node* tail;
    int size;
    int capacity;
} CircularQueue;

// Function to create a new Circular Queue
CircularQueue* createQueue(int capacity) {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->capacity = capacity;
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

// Function to add an element to the Circular Queue
void enqueue(CircularQueue* queue, int data) {
    if (queue->size == queue->capacity) {
        printf("Queue is full\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->tail == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->size++;
}

// Function to remove an element from the Circular Queue
void dequeue(CircularQueue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = queue->head;
    queue->head = temp->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(temp);
    queue->size--;
}

// Function to print the Circular Queue
void printQueue(CircularQueue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = queue->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        if (temp == queue->head) {
            break;
        }
    }
    printf("\n");
}

int main() {
    CircularQueue* queue = createQueue(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printQueue(queue);
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);
    return 0;
}