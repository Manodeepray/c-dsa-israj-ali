
#include <stdio.h>
int main()
{
    int n,max,i,j;
    printf("enter the number of elements in an arrays");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements in the array \n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("the elements in the array \n");
    for ( i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n ; j++)
        {
            max=arr[i];
            if (arr[j]>max)
            {
                max=arr[j];
                
                printf(" %d ",max);
                break;
            }
            else
            {
                printf(" -1 ");
            }
            


        }
        
    }
    
    

    return 0;
}