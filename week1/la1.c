///wap to find out the smallest and largest element stored in an array of n integers
#include <stdio.h>
int main()
{
    int n,max,min,i;
    printf("enter the number of elements in an arrays");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements in an arrays \n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    max=a[0];
    for ( i = 0; i < n; i++)
    {
        if (a[i]>max)
        {
            max=a[i];
        }
        
    }
    
    printf("the largest no in array = %d \n",max);
    min=a[0];
    for ( i = 0; i < n; i++)
    {
        if (a[i]<min)
        {
            min=a[i];
        }
        
    }
    
    printf("the smallest no in array = %d",min);

    return 0;
}