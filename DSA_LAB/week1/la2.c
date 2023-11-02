///WAP to reverse the contents of a dynamic array of n elements.
#include <stdio.h>
int main()
{
    int n,max,min,i;
    printf("enter the number of elements in an arrays");
    scanf("%d",&n);
    int a[n],b[n];
    printf("enter the elements in an arrays \n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("the array  = \n");
    for ( i = 0; i < n ; i++)
    {
       printf("%d",a[i]);
       b[n-i-1]=a[i];
    }
    
    printf("the array in reverse  = \n");
    for ( i = 0; i < n ; i++)
    {
       printf("%d",b[i]);
       
    }
    


    return 0;
}
