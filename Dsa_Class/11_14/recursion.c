#include <stdio.h>
int factorial = 1;
void fact(int i)
{
    printf(" %d ", i);
    factorial = factorial * i;
    if (i > 1)
    {
        fact(i - 1);
    }
}
int main()
{
    int i;
    printf("entr the no. :");
    scanf("%d", &i);
    printf(" the factorial of %d is :\n", i);
    fact(i);

    printf("\nfactorial : %d", factorial);
    return 0;
}