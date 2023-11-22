/*
Queue operations work as follows:

Two Indicators FRONT and REAR

- FRONT track the first element of the queue
- REAR track the last element of the queue

- Initialization: FRONT=-1 and REAR=-1
*/

#include <stdio.h>
#include <stdlib.h>

void enqueue();
void dequeue();
void isEmpty();
void isFull();
void peek();
void show();
void Elements();

int f = -1;
int r = -1;
#define n 10
int array[n];

int main()
{

    int ch;

    while (1)
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Display the First Element\n");
        printf("5.Display if Queue is Empty\n");
        printf("6.Display if Queue is Full\n");
        printf("7.Display the Number of Present Elements in Queue\n");
        printf("8.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            show();
            break;
        case 4:
            peek();
            break;
        case 5:
            isEmpty();
            break;
        case 6:
            isFull();
            break;
        case 7:
            Elements();
            break;
        case 8:
            exit(0);
        default:
            printf("Incorrect choice \n");
        }
    }
}

void enqueue()
{
    int x;
    printf("enter the element you want to enter :");
    scanf("%d", &x);
    if (f = -1 && r == -1)
    {
        f = 0;
        r = 0;
        array[f] = x;
    }
    else if ((r - f + 1) < n)
    {

        if (f <= r)
        {
            r = r + 1;
            array[r] = x;
        }
    }

    else
    {
        printf("queue is full .\n");
    }
}

void dequeue()
{
    if (f > r || f == r == -1)
    {
        printf("queue is empty \n");
        f = r = -1;
    }
    else
    {
        printf("element deleted from queue %d\n", array[f]);
        f = f + 1;
    }
}

void isEmpty()
{
    if (f == -1 && r == -1)
    {
        printf("queue is empty\n");
    }

    else
    {
        printf("queue is not empty\n");
    }
}

void isFull()
{
    if ((r - f + 1) == n)
    {
        printf("queue is full\n");
    }
    else
    {
        printf("queue not full\n ");
    }
}

void peek()
{
    if (f == r == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("peek operation shows : %d \n", array[f]);
    }
}

void Elements()
{

    if (f == r == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        int i;
        i = (r - f + 1);
        printf("no of elements in queue %d\n", i);
    }
}

void show()
{
    if (f == r == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        int i;

        printf("queue is : \n");
        for (i = f; i <= r; i++)
        {
            printf(" %d ", array[i]);
        }

        printf("\n");
    }
}
