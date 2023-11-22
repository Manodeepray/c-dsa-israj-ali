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
    struct node *ptr;
    int x, a;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Memory Full");
        return NULL;
    }

    printf("\nEnter the data for the current node: ");
    scanf("%d", &x);
    ptr->data = x;

    printf("\nDo you want to create left child of the current node %d,\n1. Yes\n2. No\n", x);
    scanf("%d", &a);

    if (a == 1)
    {
        ptr->left = create();
    }
    else if (a == 2)
    {
        ptr->left = NULL;
    }
    else
    {
        printf("\nWrong Choice entered");
    }

    printf("\nDo you want to create right child of the current node %d,\n1. Yes\n2. No\n", x);
    scanf("%d", &a);
    if (a == 1)
    {
        ptr->right = create();
    }
    else if (a == 2)
    {
        ptr->right = NULL;
    }
    else
    {
        printf("\nWrong Choice entered.");
    }

    return ptr;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1) Create a tree\n2) Perform preoder traversal\n3) Perform postorder traversal\n4) Perform inorder traversal\n5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = create();
            break;
        case 2:
            printf("\nPreorder traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 3:
            printf("\nPostorder traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 4:
            printf("\nInorder traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            exit(0);
        default:
            printf("Incorrect choice \n");
        }
    }
    return 0;
}