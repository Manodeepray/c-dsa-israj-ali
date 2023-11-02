/*WAP to convert a given singly linked list to a circular list.*/

#include<stdio.h>
#include<stdlib.h>

struct SingleLL
{
    int Data;
    struct SingleLL* Next;
    
};
struct SingleLL *Head=NULL,*Temp;

void createNode(){

    int x;
    struct SingleLL *p;
    p=(struct SingleLL *)malloc(sizeof(struct SingleLL));

    if (p == NULL)
    {
        printf("No memory available \n");
    }
    else{
    
        printf("enter the data for node 1 :\n");
        scanf("%d",&x);//scanf("%d",pi-> Data);
        p-> Data = x;
        p-> Next = NULL;
        if(Head==NULL){
            Head = p;
            Temp = p;
        }
        else{
            Temp->Next=p;
            Temp=p;
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

void SingleToCirc(){
    struct SingleLL *Temp3 = Head;

    if (Temp3 == NULL)
    {   
        printf("\n Linked List is Empty ");
        return;
    }
    
    while(Temp3->Next != NULL)
    {
        Temp3 = Temp3->Next;
    }
    
    Temp3->Next=Head;
}
    
    



int main(){

    int n,i=1;
    while (i=1)
    {
        
        printf("menu : \n1.create node :\n2. show the list \n3. convert to circular \n4. exit\nenter the option :");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            createNode();
            break;
            
        case 2:
            traversal();
            break;

        case 3:
            SingleToCirc();
            break;

        case 4:
            i=0;
            break;
        
        default:
            break;
        }
    }
    
    
    return 0;
    
}