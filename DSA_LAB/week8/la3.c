#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Define stack structure
struct Stack
{
    int top;
    unsigned capacity;
    char *array;
};

// Function to create a stack
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, char op)
{
    stack->array[++stack->top] = op;
}

// Function to pop an element from the stack
char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$'; // Return a non-valid character to indicate an empty stack
}

// Function to check if a given character is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to return precedence of operators
int precedence(char ch)
{
    switch (ch)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char *infix)
{
    int i, k;
    struct Stack *stack = createStack(MAX);
    if (!stack)
        return;

    for (i = 0, k = -1; infix[i]; ++i)
    {
        if (isalnum(infix[i]))
        {
            infix[++k] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(stack, '(');
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(stack) && stack->array[stack->top] != '(')
            {
                infix[++k] = pop(stack);
            }
            if (!isEmpty(stack) && stack->array[stack->top] != '(')
            {
                printf("Invalid expression!\n");
                return;
            }
            else
            {
                pop(stack);
            }
        }
        else
        {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(stack->array[stack->top]))
            {
                infix[++k] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack))
    {
        infix[++k] = pop(stack);
    }
    infix[++k] = '\0';
    printf("Postfix expression: %s\n", infix);
}

// Function to convert infix to prefix
void infixToPrefix(char *infix)
{
    int i, k;
    int len = strlen(infix);
    char temp;

    for (i = 0; i < len / 2; ++i)
    {
        temp = infix[i];
        infix[i] = infix[len - i - 1];
        infix[len - i - 1] = temp;
    }

    for (i = 0; infix[i]; i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
            i++;
        }
    }

    infixToPostfix(infix);
}

int main()
{
    char infix[MAX];
    printf("\nName: Manodeep Ray \nRoll No:2230028\n");
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);
    infixToPrefix(infix);

    return 0;
}