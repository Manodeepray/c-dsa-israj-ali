///wap to search an element in a dynamic array of size n
#include <stdio.h>
int main()
{
    int n,x,i,b=0;
    printf("enter the number of elements in an arrays");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements in an arrays \n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    

    printf("the array  = \n");
    for ( i = 0; i < n ; i++)
    {
       printf("%d",a[i]);
    }

    printf("\nenter the element \n");
    scanf("%d",&x);

    printf("the address of the element = \n");
    for ( i = 0; i < n ; i++)
    {
       if (a[i]==x)
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
