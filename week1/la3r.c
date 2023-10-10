///wap to search an element in a dynamic array of size n
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,x,i,b=0;
    printf("enter the number of elements in an arrays");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("enter the elements in an arrays \n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    

    printf("the array  = \n");
    for ( i = 0; i < n ; i++)
    {
       printf("%d",arr[i]);
    }

    printf("\nenter the element \n");
    scanf("%d",&x);

    printf("the address of the element = \n");
    for ( i = 0; i < n ; i++)
    {
       if (arr[i]==x)
       {
        b=1;
        printf("%d",i+1);
       }
      
    }
    
    if (b==0)
    {
    printf("element not found\n");
    }
    

    return 0;
}
