/// given an unsorted dynamic array fon size n, WAP to display the number of elements between two elements a and b
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,i,j,k,counter=0;
    printf("enter the number of elements in an arrays :\n");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("enter the elements in an arrays \n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    

    printf("the array  = \n");
    printf("{");
    for ( i = 0; i < n ; i++)
    {
       printf(" %d ",arr[i]);
    }
    printf("}");

    printf("\nenter the  element a: \n");
    scanf("%d",&a);
    printf("\nenter the  element b: \n");
    scanf("%d",&b);

   
    for ( i = 0; i < n ; i++)
    {
       if (arr[i]==a)
       {
        j=i;
       }
       if (arr[i]==b)
       {
        k=i;
       }
      
    }
    printf("first no :%d and 2nd no : %d \n",arr[j],arr[k]);
    for ( i = j+1; i <k; i++)
    {
        counter+=1;
        printf("%d",arr[i]);
    }
    printf("\n");
    printf("the number of elements : %d\n",counter);
    
    


    return 0;
}