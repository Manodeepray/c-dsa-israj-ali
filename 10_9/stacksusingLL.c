#include<stdio.h>
#include<stdlib.h>
struct singleLL
{
    int data;
    struct singleLL *Next;
    
};

struct singleLL *Head=NULL, *Top,*temp==NULL;

void createNode()
{
    struct singleLL *ptr;
    ptr=(struct singleLL*)malloc(sizeof(struct singleLL));
    int x;
    if (ptr==NULL)
    {
        printf("no memory allocated ");

    }
    else 
    {
        printf("\nEnter the value of node:");
        scanf("%d",x);
        ptr ->data=x;
        ptr ->Next=NULL;
        
        if(Head==NULL){
            Head=ptr;
            temp=ptr;		
        }
        else{
            temp->Next=ptr;
            temp=ptr;
        }
    
    }

    

}
void pushElement();
int main(){
    int i=1;
    while (i==1)
    {
        pushElement();
    }
    



    return 0;
}

void pushElement(){
	struct singleLL *temp2;
	
	if(Head==NULL){
		createNode();
	}
	else{
		
		temp2=Head;
		while(temp2!=NULL){
			//printf("%d\t",temp2->data);
			temp2=temp2->Next;
		}
		struct singleLL *p;
		int x;
		p=(struct singleLL*)malloc(sizeof(struct singleLL)); 
		
		printf("\n Enter the dat");
		scanf("%d",&x);
		
		p->data=x;
		p->Next=NULL;
		temp2->Next=p;
	}
}