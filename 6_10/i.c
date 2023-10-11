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
	void TraversalCirc();

	void insert_End();
	void insert_beginning();
	void insert_after();
	void deletion_End();
	void deletion_beginning();
	void deletion_after();

	void convertCirc();
	void insert_Circ();
	void insert_CircEnd();
	void delete_CircEnd();
	void delete_CircBeginning();

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
			int option,z,option2;
			printf("Select an option:\n");
	

			printf("1. create a Single LL \n");
			printf("2. traversal \n");

			printf("3. insert at the beginning\n");
			printf("4. insert at the end\n");
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
			printf("19. delete after the element DLL \n");
			printf("20. delete before the element DLL\n");


			printf("21. EXIT\n");		

			printf("Enter the option number: ");
			scanf("%d", &option);

			switch (option) {
				case 1:
					create();
					break;
				case 2:
					printf("1.traversal single\n2.traversal circular\nenterr option:");
					scanf("%d",&option2);
					switch (option2)
					{
					case 1:
						Traversal();
						break;
					case 2:
						TraversalCirc();
						break;
					
					default:
						break;
					}
					
					break;

				case 3:
					insert_beginning();
					break;
				case 4:
					insert_End();
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
					printf("1.insert beginning \n2.insert end\nenterr option:");
					scanf("%d",&option2);
					switch (option2)
					{
					case 1:
						insert_Circ();
						break;
					case 2:
						insert_CircEnd();
						break;
					
					default:
						break;
					}
					
					break;
				case 11:
					printf("1.delete beginning \n2delete end\nenterr option:");
					scanf("%d",&option2);
					switch (option2)
					{
					case 1:
						delete_CircEnd();
						break;
					case 2:
						delete_CircBeginning();
						break;
					
					default:
						break;
					}
					
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
			temp->Prev;
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
			while(temp2->Next!=NULL){
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
			if (y>counter)
			{
				printf("overflow condition");
				exit(0);
			}
			
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
		temp3=head;
		if (head == NULL) {
			printf("The list is empty\n ");
			return;
		}

		if (head->Next==NULL)
		{
			free(head);
			head=NULL;
			counter--;
			return;
		}
		
		while (temp3->Next!=NULL)
		{
			temp3=temp3->Next;

		}
		free(temp3->Next);
		temp3->Next=NULL;
		

		counter-=1;
	}

	void deletion_beginning(){
		struct SingleList *temp4;
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
			if (y>counter)
			{
				printf("overflow condition");
				exit(0);
			}
			
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


	void TraversalCirc(){
		struct SingleList *temp2;
		temp2 = head;
		if (head == NULL) {
			printf("Circular Linked List is empty.\n");
			return;
		}
		do {
			printf("%d\t", temp2->data);
			temp2 = temp2->Next;
		} while (temp2 != head);
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


			p->Next= head;
			temp10->Next = p;
			head=p;
		counter+=1;
	}

	void insert_CircEnd(){
		struct SingleList *temp15;
		temp15 = head;
		if (head==NULL)
		{
			printf("empty list");
		}

		while (temp15->Next != head)
		{
			temp15=temp15->Next;

		}
		
		
		struct SingleList *p;
			int x;
			p=(struct SingleList*)malloc(sizeof(struct SingleList)); 
			
			printf("\n Enter the data");
			scanf("%d",&x);
			
			p->data=x;
			p->Next=NULL;


			p->Next= head;
			temp15->Next = p;
			

		counter+=1;
	}

	void delete_CircEnd(){

		struct SingleList *temp11,*temp12;
		temp11 = head;
		temp12 = head;
		if (head==NULL)
		{
			printf("empty list");
		}

		while (temp11->Next!= head)
		{
			temp11=temp11->Next;

		}
		while (temp12->Next != temp11)
		{
			temp12=temp12->Next;

		}
		temp12->Next=head;
		temp11->Next=NULL;
		counter-=1;
	}

	void delete_CircBeginning(){
		struct SingleList *temp11,*temp12;
		temp11 = head;
		temp12 = head->Next;
		if (head==NULL)
		{
			printf("empty list");
		}
		if (head->Next==NULL)
		{	
			free(head);
		}
		while (temp12->Next!= head)
		{
			temp12=temp12->Next;

		}
		temp12->Next=temp11->Next;
		head=temp11->Next;
		free(temp11);

	counter-=1;
	}

	void convertdoublyList(){

		struct SingleList *temp13,*temp14;
		temp13 = head;
		temp14 = head;
		if (head==NULL)
		{
			printf("empty list");
		}

		while (temp13->Next != NULL)
		{	temp13->Prev=temp14;
			temp14=temp13;
			temp13=temp13->Next;

		}

		temp13->Next = NULL;
		tail = temp13;

		head->Prev=NULL;


	}
	void insertDLL_End(){
		struct SingleList *temp2;
		
		if(head==NULL){
			create();
		}
		else{
			

			struct SingleList *p;
			int x;
			p=(struct SingleList*)malloc(sizeof(struct SingleList)); 
			
			printf("\n Enter the dat");
			scanf("%d",&x);
			
			p->data=x;
			p->Next=NULL;
			tail->Next=p;
			p->Prev=tail;
			tail=p;
		}
		counter+=1;
		
	}
	void insertDLL_beginning(){
		struct SingleList *temp2;
		
		if(head==NULL){
			create();
		}
		else{
			
			temp2=head;
			while(temp2->Next!=NULL){
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

	void insertDLL_after(){
		printf("not done yet");
	}

	void insertDLL_before(){
		printf("not done yet");
	}

	void deleteDLL_End(){
		printf("not done yet");
	}
	void deleteDLL_beginning(){
		printf("not done yet");
	}
	void deleteDLL_after(){
		printf("not done yet");
	}
	void deleteDLL_before(){
		printf("not done yet");
	}