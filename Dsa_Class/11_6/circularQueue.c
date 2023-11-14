#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *Next;
};

struct circularQueue
{
    struct Node *head;
    struct Node *tail;
    int size;
    int capacity;
};

struct circularQueue *createCQ()
{
    int capacity;
    struct circularQueue *queue;
    queue = (struct circularQueue *)malloc(sizeof(struct circularQueue));
    printf("\n enter capacity of the queue :");
    scanf("%d", &capacity);
    printf("\n");

    queue->capacity = capacity;
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue();
void dequeue();
void isEmpty();
void isFull();
void peek();
void show();
void Elements();

int main()
{
    int ch;
    struct circularQueue *queue;
    while (1)
    {
        printf("1. insert capacity of circular queue \n");
        printf("3. Enqueue Operation\n");
        printf("4. Dequeue Operation\n");
        printf("5. Display the Queue\n");
        printf("6. Display the First Element\n");
        printf("7. Display if Queue is Empty\n");
        printf("8. Display if Queue is Full\n");
        printf("9. Display the Number of Present Elements in Queue\n");
        printf("10. Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            queue = createCQ();
            break;

        case 3:
            enqueue(queue);
            break;
        case 4:
            dequeue(queue);
            break;
        case 5:
            show(queue);
            break;
        case 6:
            peek(queue);
            break;
        case 7:
            isEmpty(queue);
            break;
        case 8:
            isFull(queue);
            break;
        case 9:
            Elements(queue);
            break;
        case 10:
            exit(0);
        default:
            printf("Incorrect choice \n");
        }
    }
}

void enqueue()
{
}

void dequeue()
{
}

void isEmpty()
{
}

void isFull()
{
}

void peek()
{
}

void show()
{
}

void Elements()
{
}