#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int row;
    int col;
    int value;
    struct Node *next;
} Node;

void insertNode(Node **head, int row, int col, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayMatrix(Node *head, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Node *temp = head;
            while (temp != NULL && temp->row != i && temp->col != j)
            {
                temp = temp->next;
            }
            if (temp != NULL)
            {
                printf("%d ", temp->value);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int rows, cols, nonZeroElements;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    Node *head = NULL;

    printf("Enter the non-zero elements of the matrix:\n");
    printf("Enter the row index, column index, and value of each non-zero element:\n");
    nonZeroElements = 0;
    do
    {
        int row, col, value;
        scanf("%d %d %d", &row, &col, &value);
        insertNode(&head, row, col, value);
        nonZeroElements++;
    } while (nonZeroElements < (rows * cols) / 2);

    printf("The sparse matrix representation using linked list:\n");
    displayMatrix(head, rows, cols);

    return 0;
}
