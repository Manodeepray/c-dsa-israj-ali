#include<stdio.h>
#include<stdlib.h>

struct DoubleLL
{
    int Data;
    struct DoubleLL* Next;
    struct DoubleLL* Prev;
    
};
struct DoubleLL *Head,*Tail;



int main(){

    int x;
    struct DoubleLL *p1,*p2,*p3;
    p1=(struct DoubleLL *)malloc(sizeof(struct DoubleLL));
    printf("enter the data for node 1 :\n");
    scanf("%d",&x);//scanf("%d",pi-> Data);
    p1-> Data = x;
    p1-> Next = NULL;
    p1-> Prev = NULL;
    Head = p1;

    p2=(struct DoubleLL *)malloc(sizeof(struct DoubleLL));
    printf("enter the data for node 2 :\n");
    scanf("%d",&x);//scanf("%d",pi-> Data);
    p2-> Data = x;
    p2-> Next = NULL;
    p2-> Prev = p1;
    p1-> Next = p2;

    p3=(struct DoubleLL *)malloc(sizeof(struct DoubleLL));
    printf("enter the data for node 3 :\n");
    scanf("%d",&x);//scanf("%d",pi-> Data);
    p3-> Data = x;
    p3-> Next = NULL;
    p3-> Prev = p2;
    p2-> Next = p3;
    Tail = p3;


    
    return 0;
    
}