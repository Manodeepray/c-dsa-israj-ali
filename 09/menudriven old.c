#include <stdio.h>

	void insert_beginning(int arr1[],int n,int x){
		int i;
		n=n+1;
		int arr2[n];
		arr2[0]=x;
		for(i=1;i<n+1;i++){
			arr2[i]=arr1[i- 1];
			}
					
		printf( "the new array  : \n");
		for (i=0;i<n;i++){
			printf(" %d ",arr2[i]);	
			}	
	}

	void insert_after(int arr1[],int n,int x,int y){
		int i,j;
		n=n+1;
		int arr2[n];
		arr2[0]=x;
		for(i=0;i<n;i++){
			if(arr1[i]==x){
				j=i+1;
				}
			}
		for(i=0;i<j;i++){
			arr2[i]=arr1[i];
			}        
		 arr2[j]=y;
		 
		 for(i=j+1;i<n;i++){
			arr2[i]=arr1[i-1];
			} 
		 	        
		printf( "the new array  : \n");
		for (i=0;i<n;i++){
			printf(" %d ",arr2[i]);	
			}	
	}

	void insert_before(int arr1[],int n,int x,int y){
		int i,j;
		n=n+1;
		int arr2[n];
		arr2[0]=x;
		for(i=0;i<n;i++){
			if(arr1[i]==x){
				j=i;
				}
			}
		for(i=0;i<j;i++){
			arr2[i]=arr1[i];
			}  
			      
		 arr2[j]=y;
		 
		 for(i=j+1;i<n;i++){
			arr2[i]=arr1[i-1];
			} 
		 	        
		printf( "the new array  : \n");
		for (i=0;i<n;i++){
			printf(" %d ",arr2[i]);	
			}	
	}

	void insert_end(int arr1[],int n,int x){
		int i;
		n=n+1;
		int arr2[n];	 
		for(i=0;i<n;i++){
			arr2[i]=arr1[i];
			}
		arr2[n-1]=x;
		printf( "the new array  : \n");
		for (i=0;i<n;i++){
		 	printf(" %d ",arr2[i]);	
			}


	}

	void delete_beginning(int arr1[],int n){
		int i;
		int arr2[n];
		int m=n-1;
		for(i=0;i<n;i++){
		      	arr2[i]=arr1[i+1];
			}
		printf( "the new array  : \n");
		for (i=0;i<m;i++){
			printf(" %d ",arr2[i]);
			}

	}

	void delete_end(int arr1[],int n){
		int i;
		int m=n-1;
		int arr2[m];
		for(i=0;i<m;i++){
			arr2[i]=arr1[i];
			}
		
		printf( "the new array  : \n");
		for (i=0;i<m;i++){
			printf(" %d ",arr2[i]);
			}

	}

	void delete_after(int arr1[],int n,int x){
		int i,j;
		int m=n-1;
		int arr2[n];
		for(i=0;i<n;i++){
			if(arr1[i]==x){
				j=i+1;
				}
			}
		for(i=0;i<j;i++){
			arr2[i]=arr1[i];
			}
		for(i=j;i<n;i++){
			arr2[i]=arr1[i+1];
			}		
		printf( "the new array  : \n");
		for (i=0;i<m;i++){
			printf(" %d ",arr2[i]);
			}

	}

	void delete_before(int arr1[],int n,int x){
		int i,j;
		int arr2[n];
		int m=n-1;
		for(i=0;i<n;i++){
			if(arr1[i]==x){
				j=i-1;
				}
			}
		for(i=0;i<j;i++){
			arr2[i]=arr1[i];
			}
		for(i=j+1;i<n;i++){
			arr2[i-1]=arr1[i];
			}
		printf( "the new array  : \n");
		for (i=0;i<m;i++){
			printf(" %d ",arr2[i]);
			}

	}

	void sort(int arr1[],int n){
		int i,j;
		int arr2[n];
		int temp;
		
		for (int i = 0; i < n - 1; i++) {
		    for (int j = 0; j < n - i - 1; j++) {
		        if (arr1[j] > arr1[j + 1]) {
		            // Swap arr[j] and arr[j + 1]
		            int temp = arr1[j];
		            arr1[j] = arr1[j + 1];
		            arr1[j + 1] = temp;
		        }
		    }
		}
	   
		
		printf( "the new array  : \n");
		for (i=0;i<n;i++){
			printf(" %d ",arr1[i]);
			}

	}

	int search(int arr1[],int n,int x){
		int i,j;
		for(i=0;i<n;i++){
			if(arr1[i]==x){
				j=i+1;
				}
			}
		
		printf( "the location of the element %d is %d   : \n",x,j);
		

	}



	int main(){
		int i,n;
		int option;
		printf("enter the no of elements : \n");
		scanf("%d",&n);
		int arr1[n];
		int x,y,z=1;
		

		printf("enter the elements : \n");
		for (i=0;i<n;i++){
			scanf("%d",&arr1[i]);	
		
		}
		
		printf( "the elements : \n");
		for (i=0;i<n;i++){
			printf(" %d ",arr1[i]);	
		
		}
		while(z==1){
			int option;
			    printf("Select an option:\n");
	    		printf("1.  insert at the beginning\n");
	    		printf("2.  insert at the end\n");
	    		printf("3.  insert after the element\n");
	    		printf("4.  insert before the element\n");    		
	   		    printf("5.  delete from the beginning\n");
	    		printf("6.  delete from the end\n");
	    		printf("7.  delete after the element\n");  
			    printf("8.  delete before the element\n");
		    	printf("9.  sort the elements\n");
			    printf("10. search for the element\n");    		  		
	    		printf("11. stop the loop\n");
	    
			    
			printf("Enter the option number: ");
			    scanf("%d", &option);
			    
			switch(option) {
				case 1:
					
					printf(" enter the no you want to enter :\n");
					scanf("%d",&x);
					insert_beginning(arr1,n,x);
				       
					
				    break;
				    
				    
				case 2: 
					
					printf(" enter the no you want to enter :\n");
					scanf("%d",&x);
					insert_end(arr1,n,x);
				    break;
				
				case 3: 
					
					printf(" enter the element you want to enter after :\n");
					scanf("%d",&x);
					printf(" enter the no you want to enter :\n");
					scanf("%d",&y);
					
					insert_after(arr1,n,x,y);
				    break;
				    
				case 4: 
					
					printf(" enter the element you want to enter before :\n");
					scanf("%d",&x);
					printf(" enter the no you want to enter :\n");
					scanf("%d",&y);
					
					insert_before(arr1,n,x,y);
				    break;    
				    
				case 5: 
					delete_beginning(arr1,n);
				       	
				    break;
				    
				    
				case 6: 
					
					delete_end(arr1,n);
					
				    break;
				    
				    
				case 7: 
					printf(" enter the element you want to delete after :\n");
					scanf("%d",&x);
					delete_after(arr1,n,x);
				    break;
				    
				
				case 8: 
					printf(" enter the element you want to delete before :\n");
					scanf("%d",&x);
					delete_before(arr1,n,x);
					
				    break;
				    
					
				case 9: 
					
					sort(arr1,n);
					
				    break;
				    
				    
				case 10: 
					printf(" enter the element you want to search for :\n");
					scanf("%d",&x);
					search(arr1,n,x);   
					
				    break;
				    
				    
					
					    
				case 11: z=10;
				    break;
				default: printf("Wrong option selected.\n");
			}
				
		
		
			printf("\n");
			}


		return 0;
		}