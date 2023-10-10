# include<stdio.h>
# include<stdlib.h>
void create();
void traversal();
void DeletionEnd();
void DeletionStart();
void DeletionBefore();
void DeletionAfter();
void InsertionEnd();
void InsertionStart();
void InsertionBefore();
void InsertionAfter();



struct SingleList{
	int data;
	struct SingleList *Next;
} ;
struct SingleList *head=NULL, *temp;
struct SingleList *temp2;


int main(){
	int x;
	create();
	create();
	create();
	create();
	traversal();
    DeletionEnd();
    traversal();	
}
void create(){
	struct SingleList *p;
	int x;
	p=(struct SingleList*)malloc(sizeof(struct SingleList));
	if(p==NULL){
		printf("No memory available");
	}
	else{
		printf("\n Entert the data");
		scanf("%d",&x); 
		p->data=x; //scanf("%d",p1->data);
		p->Next=NULL;
		if(head==NULL){
			head=p;
			temp=p;
		}
		else{
			temp->Next=p;		
			temp=p;
		}			
	}
	
}
void traversal(){
	
	temp2=head;
	while(temp2!=NULL){
		printf("%d\t",temp2->data);
		temp2=temp2->Next;
	}
    printf("\n");
}

void DeletionEnd(){
    struct SingleList *temp1,*temp2;
	temp1=head;
    temp2=head;
	while(temp1!=NULL){
		
		temp1=temp1->Next;
	}
    while(temp2->Next!=temp1){
		
		temp2=temp2->Next;
	}
    temp2->Next=NULL;
	temp2 = temp;
    free(temp1);

    struct SingleList *temp3;
	temp3=head;
	while(temp3!=NULL){
		printf("%d\t",temp3->data);
		temp3=temp3->Next;
	}


}