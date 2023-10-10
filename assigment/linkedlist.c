# include<stdio.h>
# include<stdlib.h>
int counter=0;
struct SingleList{
	int data;
	struct SingleList *Next;
	struct SingleList *Prev;
	
};

struct SingleList *head=NULL, *temp=NULL , *tail=NULL;
void create();
void Traversal();
void insert_End();
void insert_beginning();
void insert_after();
void deletion_End();
void deletion_beginning();
void deletion_after();

void convertCirc();
void insert_Circ();
void delete_Circ();

void convertdoublyList();
void insertDLL_End();
void insertDLL_beginning();
void insertDLL_after();
void insertDLL_before();
void deleteDLL_End();
void deleteDLL_beginning();
void deleteDLL_after();
void deleteDLL_before();

int main(){
		
	while (1) {
        int option;
        printf("Select an option:\n");
 

        printf("1. create a Single LL \n");
        printf("2. traversal \n");

        printf("3. insert at the beginning\n");
		printf("4. insert at the end\n")
        printf("5. insert after the element\n");
        
        printf("6. delete from the beginning\n");
        printf("7. delete from the end\n");
        printf("8. delete after the element\n");
       

        printf("9. convert to circular LL\n");
        printf("10. insertion circular LL\n");
        printf("11. deletion circular LL\n");


		printf("12. convert to DLL \n");
        printf("13. insert at the beginning DLL\n");
		printf("14. insert at the end DLL\n");	
        printf("15. insert after the element DLL\n");
		printf("16. insert before the element DLL\n");
        
        printf("17. delete from the beginning DLL\n");
        printf("18. delete from the end DLL\n");
        printf("19. delete after the element DLL \n")
		printf("20. delete before the element DLL\n");


		printf("21. EXIT\n");		

        printf("Enter the option number: ");
        scanf("%d", &option);

        switch (option) {
			case 1:
                create();
                break;
            case 2:
                Traversal();
                break;

            case 3:
                insert_End();
                break;
            case 4:
				insert_beginning();
                break;
            case 5:
                insert_after();
                break;


            case 6:
                deletion_beginning();
                break;
            case 7:
                deletion_End;
                break;
            case 8:
                deletion_after();
                break;


			case 9:
                convertCirc();
                break;
            case 10:
                insert_Circ();
                break;
            case 11:
                delete_Circ();
                break;


			case 12:
                convertdoublyList();
                break;
            case 13:
                insertDLL_beginning();
                break;
            case 14:
                insertDLL_End();
                break;
			case 15:
                insertDLL_after();
                break;
            case 16:
                insertDLL_before();
                break;
			case 17:
                deleteDLL_beginning();
                break;
            case 18:
                deleteDLL_End();
                break;
			case 19:
                deleteDLL_after();
                break;
            case 20:
                deleteDLL_before();
                break;


            
            case 21:
                z = 10;
                break;
            default:
                printf("Wrong option selected.\n");
        }

        printf("\n");
        if (z == 10) {
            break;
        }
    }
	
}

void create(){
	struct SingleList *p;
	int x;
	p=(struct SingleList*)malloc(sizeof(struct SingleList));
	
	printf("\n Enter the dta : ");
	scanf("%d",&x);
	
	p->data = x;
	p->Next = NULL;
	p->Prev = NULL;
	
	if(head==NULL){
		head = p;
		tail = p;
		temp = p;		
	}
	else{
		temp->Next=p;
		temp=p;
		temp->Next=NULL;
		temp->Prev
	}
	counter+=1;

	
}

void Traversal(){
	struct SingleList *temp2;
	temp2=head;
	while(temp2!=NULL){
		printf("%d\t",temp2->data);
		temp2=temp2->Next;
	}
}
void insert_beginning(){
	struct SingleList *temp5;
	
	if(head==NULL){
		create();
	}
	else{
		struct SingleList *p;
		int x;
		p=(struct SingleList*)malloc(sizeof(struct SingleList)); 
		
		printf("\n Enter the data");
		scanf("%d",&x);
		
		p->data = x;
		p->Next = NULL;
		temp5 = head;
		p->Next = temp5;
		head = p;

		
	}
	counter+=1;
}

void insert_End(){
	struct SingleList *temp2;
	
	if(head==NULL){
		create();
	}
	else{
		
		temp2=head;
		while(temp2!=NULL){
			//printf("%d\t",temp2->data);
			temp2=temp2->Next;
		}
		struct SingleList *p;
		int x;
		p=(struct SingleList*)malloc(sizeof(struct SingleList)); 
		
		printf("\n Enter the dat");
		scanf("%d",&x);
		
		p->data=x;
		p->Next=NULL;
		temp2->Next=p;
	}
	counter+=1;
}

void insert_after(){
	struct SingleList *temp6;
	
	if(head==NULL){
		create();
	}
	else{
		
		temp6=head;
		int y,i=1;
		printf("enter the index you want to enter after\n");
		scanf("%d",&y);
		while(i!=y){
			
			temp6=temp6->Next;
			i++;
		}
		struct SingleList *p;
		int x;
		p=(struct SingleList*)malloc(sizeof(struct SingleList)); 
		
		printf("\n Enter the data");
		scanf("%d",&x);
		
		p->data=x;
		p->Next=NULL;
		p->Next=temp6->Next;
		temp6->Next=p;

	}
	counter+=1;
}

void deletion_End(){
	struct SingleList *temp1,*temp3;
	temp1=head;
	temp3=head;
	if (head == NULL) {
		printf("The list is empty\n ");
	}
	while (temp1->Next!=NULL)
	{
		temp1=temp1->Next;

	}

	while (temp3->Next!=temp1)
	{
		temp3=temp3->Next;

	}
	temp3->Next = NULL;
	counter-=1;
}

void deletion_beginning(){
	struct SingeList *temp4;
	temp4 = head;
	if (temp4==NULL)
	{
		printf("list is empty \n");
	}
	
	else{
		head = head->Next;
		temp4->Next = NULL;

	}
	counter-=1;

}

void deletion_after()
{
	struct SingleList *temp7,*temp8;
	
	if(head==NULL){
		create();
	}
	else{
		
		temp7=head;
		int y,i=1;
		printf("enter the index you want to delete after\n");
		scanf("%d",&y);
		while(i!=y){
			
			temp7=temp7->Next;
			i++;
		}
		temp8=temp7->Next;
		temp7->Next = temp8->Next;
		temp8->Next=NULL;
		
		

	}
	counter-=1;

}

void convertCirc(){
	struct SingleList *temp9;
	temp9 = head;
	if (head==NULL)
	{
		printf("empty list");
	}

	while (temp9->Next != NULL)
	{
		temp9=temp9->Next;

	}

	temp9->Next = head;	

}




void insert_Circ(){
	struct SingleList *temp10;
	temp10 = head;
	if (head==NULL)
	{
		printf("empty list");
	}

	while (temp10->Next != head)
	{
		temp10=temp10->Next;

	}
	
	struct SingleList *p;
		int x;
		p=(struct SingleList*)malloc(sizeof(struct SingleList)); 
		
		printf("\n Enter the data");
		scanf("%d",&x);
		
		p->data=x;
		p->Next=NULL;

		p->Next= head;
		temp10->Next = p;


}
void delete_Circ(){

	struct SingleList *temp11,*temp12;
	temp11 = head;
	temp12 = head;
	if (head==NULL)
	{
		printf("empty list");
	}

	while (temp11->Next != head)
	{
		temp11=temp11->Next;

	}
	while (temp12->Next != temp11)
	{
		temp12=temp12->Next;

	}
	temp12->Next=head;
	temp11->Next=NULL

}

void convertdoublyList(){

	struct SingleList *temp13,*temp14;
	temp13 = head;
	temp14 = head;
	if (head==NULL)
	{
		printf("empty list");
	}

	while (temp13->Next != head)
	{
		temp13=temp13->Next;

	}

	temp13->Next = NULL;

	while (temp14->Next != NULL)
	{
		temp14=temp14->Next;

	}	
	tail = temp14;


}
void insertDLL_End();
void insertDLL_beginning();
void insertDLL_after();
void insertDLL_before();
void deleteDLL_End();
void deleteDLL_beginning();
void deleteDLL_after();
void deleteDLL_before();