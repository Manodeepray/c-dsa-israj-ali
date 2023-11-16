#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *Next;
};

struct Node *Head = NULL, *Tail = NULL;

void createNode();
void enqueue();
void dequeue();
void peek();
void show();

int count = 0;

int main()
{
    int ch;

    printf("\nName: Prabuddha Kumar Samanta \nRoll No:2230033\n");
    while (1)
    {
        printf("1. Create a Single LL \n");
        printf("2. Enqueue Operation\n");
        printf("3. Dequeue Operation\n");
        printf("4. Display the Queue\n");
        printf("5. Display the First Element\n");
        printf("6. Exit\n");
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
            exit(0);
        default:
            printf("Incorrect choice \n");
        }
    }
}

void createNode()
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    int x;
    printf("\nEnter the data: ");
    scanf("%d", &x);

    p->data = x;
    p->Next = NULL;

    if (Head == NULL)
    {
        Head = Tail = p;
        Tail->Next = Head;
    }
    else
    {
        Tail->Next = p;
        p->Next = Head;
        Tail = p;
    }
    count++;
}

void enqueue()
{
    if (Head == NULL)
    {
        createNode();
    }
    else
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        if (p == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }

        int x;
        printf("\nEnter the data: ");
        scanf("%d", &x);

        p->data = x;
        p->Next = Head;
        Tail->Next = p;
        Tail = p;
    }
    count++;
}

void dequeue()
{
    if (Head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = Head;

    if (Head == Tail)
    {
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->Next;
        Tail->Next = Head;
    }

    free(temp);
    count--;
}

void peek()
{
    if (Head != NULL)
    {
        printf("The first element is %d.\n", Head->data);
    }
    else
    {
        printf("Queue is empty.\n");
    }
}

void show()
{
    if (Head == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *Temp6 = Head;

    do
    {
        printf("%d ", Temp6->data);
        Temp6 = Temp6->Next;
    } while (Temp6 != Head);

    printf("\n");
}