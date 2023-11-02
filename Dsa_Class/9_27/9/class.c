#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

int Top = -1;
int A[N];
void push();       // Push element to the top of the stack
int pop();         // Remove and return the top most element of the stack
int peek();        // Return the top most element of the stack
void isEmpty();    // Check if the stack is in Underflow state or not
void isFull();     // Check if the stack is in Overflow state or not

int main(){
 

    printf("STATIC ARRAY (Total Capacity: %d)\n", N);
    int choice;
    

    while(1){
        printf("\nChoose any of the following options:\n");
        printf(" 0: Exit            1: Push            2: Pop            3: Peek\n");
        printf(" 4: Check if the stack is empty     5: Check if the stack is full\n\n");
        scanf("%d", &choice);

        switch(choice){
            case 0: exit(0);
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: isEmpty();break;
            case 5: isFull();break;
            default: printf("Please choose a correct option!");
        }
    }
    return 0;
}

void push(){
    int x;
    if (Top==N-1)
    {
        printf("stack is full \n");
    
    }
    else
        {
        Top=Top+1;
        printf("enter the value :\n ");
        scanf("%d",&x);

        A[Top]=x;
    }

    printf("the stack is : \n");
    for(int i=0; i<Top+1 ; i++)
    {
        printf(" %d ",A[i]);
    }
}

int pop(){

    if (Top==-1)
    {
        printf("stack is empty \n");
    }

    else
    {
        printf("the popped element is %d \n",A[Top]);
        Top=Top-1;
        
    }

    printf("the stack is : \n");
    for(int i=0; i<Top+1 ; i++)
    {
        printf(" %d ",A[i]);
    }
}

int peek(){
    if (Top==-1)
    {
        printf("stack is empty \n");
    }
    
    else
    {
        printf("the top most element is %d \n",A[Top]);
    }
    
    printf("the stack is : \n");
    for(int i=0; i<Top+1 ; i++)
    {
        printf(" %d ",A[i]);
    }
}

    


void isEmpty( ){
    if (Top==-1)
    {
        printf("true");
    }
    else{
        printf("false");
    }
    

}

void isFull(){
    if (Top==N-1)
    {
        printf("true");
    }
    else{
        printf("false");
    }

    
}