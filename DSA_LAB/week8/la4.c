#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, int operand)
{
    stack->array[++stack->top] = operand;
}

int pop(struct Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return -1; // Return -1 to indicate an empty stack
}

int evaluatePostfix(char *exp)
{
    struct Stack *stack = createStack(MAX);
    int i, op1, op2, result;
    for (i = 0; exp[i]; ++i)
    {
        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');
        else
        {
            op2 = pop(stack);
            op1 = pop(stack);
            switch (exp[i])
            {
            case '+':
                push(stack, op1 + op2);
                break;
            case '-':
                push(stack, op1 - op2);
                break;
            case '*':
                push(stack, op1 * op2);
                break;
            case '/':
                push(stack, op1 / op2);
                break;
            }
        }
    }
    result = pop(stack);
    free(stack->array);
    free(stack);
    return result;
}

int evaluatePrefix(char *exp)
{
    struct Stack *stack = createStack(MAX);
    int i, op1, op2, result;
    for (i = strlen(exp) - 1; i >= 0; i--)
    {
        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');
        else
        {
            op1 = pop(stack);
            op2 = pop(stack);
            switch (exp[i])
            {
            case '+':
                push(stack, op1 + op2);
                break;
            case '-':
                push(stack, op1 - op2);
                break;
            case '*':
                push(stack, op1 * op2);
                break;
            case '/':
                push(stack, op1 / op2);
                break;
            }
        }
    }
    result = pop(stack);
    free(stack->array);
    free(stack);
    return result;
}

int main()
{
    char exp[MAX];
    int choice;

    printf("Enter the expression type (1 for postfix, 2 for prefix): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter a postfix expression: ");
        scanf("%s", exp);
        int result = evaluatePostfix(exp);
        printf("The result of the postfix expression is: %d\n", result);
    }
    else if (choice == 2)
    {
        printf("Enter a prefix expression: ");
        scanf("%s", exp);
        int result = evaluatePrefix(exp);
        printf("The result of the prefix expression is: %d\n", result);
    }
    else
    {
        printf("Invalid choice!\n");
    }

    return 0;
}