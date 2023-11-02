/*WAP to convert a given singly linked list to a circular list.*/

#include<stdio.h>
#include<stdlib.h>

struct SingleLL
{
    int Data;
    struct SingleLL* Next;
    struct SingleLL*Prev;
    
    
};

struct SingleLL *Head=NULL, *Tail , *Temp;

void createDoublyLLNode(){

    int x;
    struct SingleLL *p;
    p=(struct SingleLL *)malloc(sizeof(struct SingleLL));

    if (p == NULL)
    {
        printf("No memory available \n");
    }
    else{
    
        printf("enter the data for node:\n");
        scanf("%d",&x);//scanf("%d",pi-> Data);
        p-> Data = x;
        p-> Next = NULL;
        p-> Prev = NULL;
        if(Head == NULL){
            Head = p;
            Tail = p;
            Temp = p;
            
        }
        else{
            Temp->Next=p;
            Tail = Temp->Next;
            p->Prev = Temp;
            Temp = p;
             
        }

        }
}

void traversal(){

    struct SingleLL *Temp2;
    Temp2=Head;
    while (Temp2!=NULL)
    {
        printf(" %d ",Temp2->Data);
        Temp2=Temp2->Next;
    }

}


    



int main(){

    int n,i=1;
    while (i=1)
    {
        
        printf("menu : \n1.create node :\n2. show the list \n3. exit\nenter the option :");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            createDoublyLLNode();
            break;
            
        case 2:
            traversal();
            break;

        case 3:
            i=0;
            break;
        
        default:
            break;
        }
    }
    
    
    return 0;
    
}