#include <stdio.h>
#include <stdlib.h>

#define n 10

void createNode();
void enqueue();
void dequeue();
void isEmpty();
void isFull();
void peek();
void show();
void Elements();

struct Node {
    int data;
    struct Node *Next;
};

struct Node *Head = NULL, *Tail = NULL, *Temp = NULL;
int count = 0;

int main() {
    int ch;
    while (1) {
        printf("1. create a Single LL \n");
        printf("2. Enqueue Operation\n");
        printf("3. Dequeue Operation\n");
        printf("4. Display the Queue\n");
        printf("5. Display the First Element\n");
        printf("6. Display if Queue is Empty\n");
        printf("7. Display if Queue is Full\n");
        printf("8. Display the Number of Present Elements in Queue\n");
        printf("9. Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        

        switch (ch) {
            case 1:
            createNode();
            break;
        case 2:
            enqueue();
            break;
        case 3:
            dequeue();
            break;
        case 4:
            show();
            break;
        case 5:
            peek();
            break;
        case 6:
            isEmpty();
            break;
        case 7:
            isFull();
            break;
        case 8:
            Elements();
            break;
        case 9:
            exit(0);
        default:
            printf("Incorrect choice \n");
        }
    }
}

void createNode() {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    int x;
    printf("\nEnter the data: ");
    scanf("%d", &x);

    p->data = x;
    p->Next = NULL;

    if (Head == NULL) {
        Head = Tail = Temp = p;
    } else {
        Tail->Next = p;
        Tail = p;
    }
    count++;
}

void enqueue() {
    if (Head == NULL) {
        createNode();
    } else {
        struct Node *temp2 = Head;
        while (temp2->Next != NULL) {
            temp2 = temp2->Next;
        }

        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        if (p == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        int x;
        printf("\nEnter the data: ");
        scanf("%d", &x);

        p->data = x;
        p->Next = NULL;
        temp2->Next = p;
        Tail = p;
    }
    count++;
}

void dequeue() {
    if (Head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp4 = Head;
    Head = Head->Next;
    temp4->Next = NULL;
    free(temp4);
    count--;
}

void isEmpty() {
    if (Head == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }
}

void isFull() {
    if (Head == NULL) {
        printf("Queue is not full (here empty).\n");
    } else {
        int count2 = 0;
        struct Node *Temp1 = Head;
        while (Temp1 != NULL) {
            count2++;
            Temp1 = Temp1->Next;
        }

        if (count2 < n) {
            printf("Queue is not full.\n");
        } else {
            printf("Queue is full.\n");
        }
    }
}

void peek() {
    if (Head != NULL) {
        printf("The first element is %d.\n", Head->data);
    } else {
        isEmpty();
    }
}

void show() {
    struct Node *Temp6 = Head;
    while (Temp6 != NULL) {
        printf("%d ", Temp6->data);
        Temp6 = Temp6->Next;
    }
    printf("\n");
}

void Elements() {
    if (Head == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("The number of elements in the queue = %d.\n", count);
    }
}