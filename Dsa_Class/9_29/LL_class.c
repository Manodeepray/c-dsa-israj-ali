#include<stdio.h>
#include<stdlib.h>

struct SingleLL
{
    int Data;
    struct SingleLL* Next;
    
};
struct SingleLL *Head;



int main(){

    int x;
    struct SingleLL *p1,*p2,*p3;
    p1=(struct SingleLL *)malloc(sizeof(struct SingleLL));
    printf("enter the data for node 1 :\n");
    scanf("%d",&x);//scanf("%d",pi-> Data);
    p1-> Data = x;
    p1-> Next = NULL;
    Head = p1;

    p2=(struct SingleLL *)malloc(sizeof(struct SingleLL));
    printf("enter the data for node 2 :\n");
    scanf("%d",&x);//scanf("%d",pi-> Data);
    p2-> Data = x;
    p2-> Next = NULL;
    p1-> Next = p2;

    p3=(struct SingleLL *)malloc(sizeof(struct SingleLL));
    printf("enter the data for node 3 :\n");
    scanf("%d",&x);//scanf("%d",pi-> Data);
    p3-> Data = x;
    p3-> Next = NULL;
    p2-> Next = p3;

    struct SingleList *temp;
	temp=Head;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->Next;
	}

    
    return 0;
    
}