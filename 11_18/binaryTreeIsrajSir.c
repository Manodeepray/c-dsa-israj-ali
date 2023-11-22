#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

struct node *create()
{
    struct node *ptr, *ptr1;
    int x, a;

    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("Memory Full");
    }
    printf("\n Enter the data for the current node  ");
    scanf("%d", &x);
    ptr->data = x;

    printf("\n Do you want to create left child of the current node %d, y/n:- ", x);

    scanf("%d", &a);

    if (a == 0 || a == 1)
    {
        // ptr1=create();
        // ptr->left=ptr1;
        ptr->left = create();
    }
    else
    {
        ptr->left = NULL;
        // return 0;
    }

    printf("\n Do you want to create right child of the current node %d, y/n:- ", x);
    scanf("%d", &a);
    if (a == 0 || a == 1)
    {
        ptr1 = create();
        ptr->right = ptr1;
    }
    else
    {
        ptr->right = NULL;
        // return 0;
    }
    return ptr;
}