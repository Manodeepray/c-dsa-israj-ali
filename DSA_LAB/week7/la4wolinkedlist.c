#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols, nonZeroElements;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    printf("Enter the non-zero elements of the matrix:\n");
    printf("Enter the row index, column index, and value of each non-zero element:\n");
    nonZeroElements = 0;
    do
    {
        int row, col, value;
        scanf("%d %d %d", &row, &col, &value);
        matrix[row][col] = value;
        nonZeroElements++;
    } while (nonZeroElements < (rows * cols) / 2);

    int transpose[cols][rows];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                transpose[j][i] = matrix[i][j];
            }
        }
    }

    printf("The transpose of the sparse matrix:\n");
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
