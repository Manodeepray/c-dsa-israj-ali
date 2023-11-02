#include<stdio.h>
#include<stdlib.h>

struct SingleLL
{
    int Data;
    struct SingleLL* Next;
    
};
struct SingleLL *Head=NULL,*Temp;

/*int count=0;*/

void createNode(){

    int x;
    struct SingleLL *p;
    p=(struct SingleLL *)malloc(sizeof(struct SingleLL));

    if (p == NULL)
    {
        printf("No memory available \n");
    }
    else{
       /* if(count == 0){
            
            printf("enter the data for node 1 :\n");
            scanf("%d",&x);//scanf("%d",pi-> Data);
            p-> Data = x;
            p-> Next = NULL;
            Head = p;
            count+=1;
        }
        else{
            printf("enter the data for node 1 :\n");
            scanf("%d",&x);//scanf("%d",pi-> Data);
            p-> Data = x;
            p-> Next = NULL;
            count+=1;
            }*/
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
    
    



int main(){

    int n,i=1;
    while (i=1)
    {
        
        printf("menu : \n1.create node :\n2. show the list \n3. exit\nenter the option :");
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
            i=0;
            break;
        
        default:
            break;
        }
    }
    
    
    return 0;
    
}