#include <stdio.h>
#include <stdlib.h>
# define SIZE 100
void enqueue();
void dequeue();
void show();
int inp_arr[SIZE];
int Rear = - 1;
int Front = - 1;
int main()
{
    int ch;
    while (1)
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:enqueue();
            break;

            case 2:dequeue();
            break;

            case 3:show();
            break;
            
            case 4:
            exit(0);
            default:
            printf("Incorrect choice \n");
            break;
        } 
    } 
} 
 
void enqueue(){ 
    if(Rear==-1 && Front==-1){
        Front=Rear=0;
        Rear+=1;
        printf("enter the element tom be entered : ");
        int x;
        scanf("%d",&x);
        inp_arr[Rear]=x;
        
    }

    else if (Front<=Rear)
    {
        Rear+=1;
        printf("enter the element tom be entered : ");
        int x;
        scanf("%d",&x);
        inp_arr[Rear]=x;
        if(Rear>=SIZE){
            Rear=0;
        }
        if (Front=Rear+1)
                {
                    exit(0);
                }
        }
    else if (Front>Rear)
    {
        Rear+=1;
        printf("enter the element tom be entered : ");
        int x;
        scanf("%d",&x);
        inp_arr[Rear]=x;
        if (Front=Rear+1)
        {
            exit(0);
        }
        
    }

    
      
    

} 
 
void dequeue(){
        if(Rear==-1 && Front==-1){
            printf("\nempty queue");
        }
        else if(Front < Rear){
            printf ("%d is deleted from queue ",inp_arr [Front]);
            Front=Front+1;
       
        }
        else if(Front == Rear){
            printf ("%d is deleted from queue ",inp_arr [Front]);
            Front=Front+1;
       
        }

        else if(Front>Rear){
            printf ("%d is deleted from queue ",inp_arr [Front] );
            Front=Front+1;
            if (Front==SIZE)
            {
                Front=0;
            }
            
        }
}
 
void show(){
    if(Rear==-1 && Front==-1){
        printf("\nempty queue");
    }
    else if (Front == Rear){
        printf ("\nqueue = front = rear =%d \n",inp_arr[Front]);
    }
    
    else if(Front<Rear){
        printf(" the queue : ");
        for(int i =Front; i<=Rear;i++){
            printf("%d ",inp_arr[i]);
        }
        printf("\n");
    }
    else if(Front>Rear){
        printf(" the queue : ");
        for(int i =0; i<=Rear;i++){
            printf("%d ",inp_arr[i]);
        }
        for(int i =Rear; i<SIZE ;i++){
            printf("%d ",inp_arr[i]);
        }
        printf("\n");
    }
}