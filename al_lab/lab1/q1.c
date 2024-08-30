#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    printf("Enter the elements :");
    int a[n];                    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)         
    {
        int temp;
        for(int j=i+1; j<n ;j++)
        {
            if(a[i]<a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("second smallest element is %d",a[n-2]);   
    printf("\n");
    printf("second largest element is %d",a[1]);      
    return 0;
}
