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

struct Node
{
    int data;
    struct Node *Next;
};

struct Node *Head = NULL, *Tail = NULL, *Temp = NULL;

int main()
{
    int ch;
    while (1)
    {
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
        switch (ch)
        {
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

void createNode()
{
    int count = 0;

    if (count <= n)
    {
        struct Node *p;
        int x;
        p = (struct Node *)malloc(sizeof(struct Node));

        printf("\n Enter the data : ");
        scanf("%d", &x);

        p->data = x;
        p->Next = NULL;

        if (Head == NULL)
        {
            Head = p;
            Temp = p;
            Tail = p;
            count = count + 1;
        }
        else
        {
            Temp->Next = p;
            Temp = p;
            Temp->Next = NULL;
            Tail = Tail->Next;
            count = count + 1;
        }
    }
}
void enqueue()
{
    int count1 = 0;
    struct Node *temp2;

    if (Head == NULL)
    {
        createNode();
        count1 = 1;
    }
    else
    {

        if (count1 <= n)
        {
            temp2 = Head;
            while (temp2->Next != NULL)
            {
                // printf("%d\t",temp2->data);
                temp2 = temp2->Next;
            }
            struct Node *p;
            int x;
            p = (struct Node *)malloc(sizeof(struct Node));

            printf("\n Enter the data \n");
            scanf("%d", &x);

            p->data = x;
            p->Next = NULL;
            temp2->Next = p;
            Tail = Tail->Next;
            count1 = count1 + 1;
        }
        else
        {
            printf("queue is full \n");
        }
    }
}
void dequeue()
{

    struct Node *temp4;
    temp4 = Head;
    if (Head == NULL)
    {
        printf("list is empty \n");
    }

    else
    {
        Head = Head->Next;
        temp4->Next = NULL;
        free(temp4);
    }
}
void isEmpty()
{

    if (Head == NULL)
    {
        printf("queue is empty \n");
    }
    else
    {
        printf("queue is not empty \n");
    }
}
void isFull()
{
    if (Head = NULL)
    {
        printf("queue is not full (here empty)\n");
    }

    else
    {
        int count2 = 0;
        struct Node *Temp1;
        Temp1 = Head;
        while (Temp1->Next != NULL)
        {
            count2 = count2 + 1;
        }

        if (count2 < n)
        {
            printf("queue in not full \n");
        }
        else
        {
            printf("queue is full\n");
        }
    }
}
void peek()
{
    if (Head != NULL)
    {
        printf("the first element is %d", Head->data);
    }
    else
    {
        isEmpty();
    }
}
void show()
{
    struct Node *Temp1;
    Temp1 = Head;
    while (Temp1->Next != NULL)
    {
        printf(" %d ", Temp1->data);
    }

    printf("\n");
}
void Elements()
{
    if (Head = NULL)
    {
        printf("queue is empty :");
    }

    else
    {
        int count = 0;
        struct Node *Temp1;
        Temp1 = Head;
        while (Temp1->Next != NULL)
        {
            count = count + 1;
        }
        printf("the no of elements inthe queue = %d", count);
    }
}
