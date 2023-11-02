#include <stdio.h>
#include <stdlib.h>

// Define the structure for a single non-zero matrix element
typedef struct SparseElement
{
    int row;
    int col;
    int value;
    struct SparseElement *next;
} SparseElement;

// Function to create a new non-zero matrix element
SparseElement *createSparseElement(int row, int col, int value)
{
    SparseElement *element = (SparseElement *)malloc(sizeof(SparseElement));
    element->row = row;
    element->col = col;
    element->value = value;
    element->next = NULL;
    return element;
}

// Function to add a non-zero element to the sparse matrix
void addSparseElement(SparseElement **matrix, int row, int col, int value)
{
    SparseElement *newElement = createSparseElement(row, col, value);
    newElement->next = *matrix;
    *matrix = newElement;
}

// Function to display the sparse matrix
void displaySparseMatrix(SparseElement *matrix, int rows, int cols)
{
    int row, col;
    for (row = 0; row < rows; row++)
    {
        for (col = 0; col < cols; col++)
        {
            int found = 0;
            SparseElement *current = matrix;
            while (current != NULL)
            {
                if (current->row == row && current->col == col)
                {
                    printf("%d ", current->value);
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found)
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    SparseElement *matrix = NULL;
    int rows, cols, nonZeroEntries;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the number of non-zero entries: ");
    scanf("%d", &nonZeroEntries);

    for (int i = 0; i < nonZeroEntries; i++)
    {
        int row, col, value;
        printf("Enter non-zero element (row, column, value): ");
        scanf("%d %d %d", &row, &col, &value);
        addSparseElement(&matrix, row, col, value);
    }

    printf("Sparse Matrix:\n");
    displaySparseMatrix(matrix, rows, cols);

    return 0;
}
