#include <stdio.h>
#include <stdlib.h>

// Define the structure for a single term in the polynomial
typedef struct Term
{
    int coefficient;
    int exponent;
    struct Term *next;
} Term;

// Function to create a new term
Term *createTerm(int coefficient, int exponent)
{
    Term *newTerm = (Term *)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to add a term to the polynomial
void addTerm(Term **polynomial, int coefficient, int exponent)
{
    Term *newTerm = createTerm(coefficient, exponent);
    if (*polynomial == NULL)
    {
        *polynomial = newTerm;
    }
    else
    {
        Term *current = *polynomial;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to display the polynomial
void displayPolynomial(Term *polynomial)
{
    if (polynomial == NULL)
    {
        printf("Polynomial is empty.\n");
        return;
    }

    while (polynomial != NULL)
    {
        if (polynomial->coefficient > 0 && polynomial != *(&polynomial))
        {
            printf("+");
        }
        printf("%dx^%d ", polynomial->coefficient, polynomial->exponent);
        polynomial = polynomial->next;
    }
    printf("\n");
}

int main()
{
    Term *polynomial = NULL;

    // Add terms to the polynomial
    addTerm(&polynomial, 5, 7);
    addTerm(&polynomial, -3, 5);
    addTerm(&polynomial, 1, 2);
    addTerm(&polynomial, 9, 0);

    printf("Polynomial: ");
    displayPolynomial(polynomial);

    return 0;
}
