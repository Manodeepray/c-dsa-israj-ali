#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int arr[MAX], i = 0;

void createRootParent()
{

    int x;
    printf("enter the data : ");
    scanf("%d", &x);
    arr[0] = x;
}
void createChild()
{
    int x, r, l;
    l = 2 * i + 1;
    r = 2 * i + 2;
    printf("enter left child : \n");
    printf("enter the data : ");
    scanf("%d", &x);
    arr[l] = x;

    printf("enter right child : \n");
    printf("enter the data : ");
    scanf("%d", &x);
    arr[r] = x;
    printf("\n");
    i++;
}
void findParent()
{
    int j = 0, x, key, p;
    printf("enter the node to find parent for : ");
    scanf("%d", &x);

    int arraySize = sizeof(arr) / sizeof(arr[0]);
    for (j = 0; j < arraySize; j++)
    {
        if (arr[j] == x)
        {
            key = j;
        }
    }
    if (key % 2 == 0)
    {
        p = (key - 2) / 2;
    }
    else
    {
        p = (key - 1) / 2;
    }

    printf("parent node for %d is %d \n", x, arr[p]);
}

void printTree()
{

    int arraySize = sizeof(arr) / sizeof(arr[0]);
    for (int j = 0; j < arraySize; j++)
    {
        printf(" %d ", arr[j]);
    }
    printf("\n");
}

int main()
{
    int n;

    while (1)
    {
        int ch;
        printf("1.create root node\n");
        printf("2.insert child node:\n");
        printf("3.find parent\n");
        printf("4.print array\n");
        printf("5.exit\n");
        printf("enter the option :\n");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            createRootParent();

            break;
        case 2:
            createChild();
            break;
        case 3:
            findParent();
            break;
        case 4:
            printTree();
            break;
        case 5:
            exit(1);
            break;

        default:
            printf("invalid option \n");
            break;
        }
    }
    return 0;
}