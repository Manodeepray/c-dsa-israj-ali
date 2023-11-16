#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the Binary Search Tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function prototypes
struct Node *insert(struct Node *root, int key);
struct Node *deleteNode(struct Node *root, int key);
struct Node *minValueNode(struct Node *node);
struct Node *search(struct Node *root, int key);
void inorderTraversal(struct Node *root);
void preorderTraversal(struct Node *root);
void postorderTraversal(struct Node *root);
int countLeafNodes(struct Node *root);
void displayPathToNode(struct Node *root, int key);

// Main function
int main()
{
    struct Node *root = NULL;
    int choice, key;

    do
    {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search for a Key\n");
        printf("4. Traversal: Inorder, Preorder, and Postorder\n");
        printf("5. Count the number of leaf nodes\n");
        printf("6. Display the path to a node\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter the key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;

        case 2:
            printf("Enter the key to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;

        case 3:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            if (search(root, key) != NULL)
                printf("Key %d is found in the tree.\n", key);
            else
                printf("Key %d is not found in the tree.\n", key);
            break;

        case 4:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("\nPreorder Traversal: ");
            preorderTraversal(root);
            printf("\nPostorder Traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;

        case 5:
            printf("Number of leaf nodes: %d\n", countLeafNodes(root));
            break;

        case 6:
            printf("Enter the key to display the path: ");
            scanf("%d", &key);
            displayPathToNode(root, key);
            break;

        case 7:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'G' && choice != 'g');

    return 0;
}

// Function to insert a node in the BST
struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// Function to delete a node with the given key from the BST
struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to find the node with the minimum value in the BST
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Function to search for a key in the BST
struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Function to perform inorder traversal of the BST
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform preorder traversal of the BST
void preorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform postorder traversal of the BST
void postorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to count the number of leaf nodes in the BST
int countLeafNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to display the path to a node in the BST
void displayPathToNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        printf("Key not found in the tree.\n");
        return;
    }

    printf("Path to Node %d: ", key);

    while (root != NULL)
    {
        printf("%d ", root->data);
        if (key < root->data)
            root = root->left;
        else if (key > root->data)
            root = root->right;
        else
            break;
    }

    printf("\n");
}
