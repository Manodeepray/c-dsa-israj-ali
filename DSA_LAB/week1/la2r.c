///WAP to reverse the contents of a dynamic array of n elements.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    printf("enter the number of elements in an arrays : \n");
    scanf("%d",&n);
    int *arra=(int*)malloc(n*sizeof(int));
    int *arrb=(int*)malloc(n*sizeof(int));

    if (arra == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
        }
    if (arrb== NULL) {
        printf("Memory allocation failed.\n");
        return 1;
        }

    printf("enter the elements in an arrays : \n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arra[i]);
    }

    printf("the array  = \n");
    for ( i = 0; i < n ; i++)
    {
       printf("%d",arra[i]);
       arrb[n-i-1]=arra[i];
    }
    
    printf("\n");
    
    printf("the array in reverse  = \n");
    for ( i = 0; i < n ; i++)
    {
       printf("%d",arrb[i]);
       
    }
    
    printf("\n");


    return 0;
}
