#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 1000
int top = -1;


void push();       // Push element to the top of the stack
int pop();         // Remove and return the top most element of the stack
int peek();        // Return the top most element of the stack
bool isEmpty();    // Check if the stack is in Underflow state or not
bool isFull();     // Check if the stack is in Overflow state or not

int main(){
    printf("STATIC ARRAY (Total Capacity: %d)\n", N);
    int choice;
    
	int A[N];

    while(1){
        printf("\nChoose any of the following options:\n");
        printf(" 0: Exit            1: Push            2: Pop            3: Peek\n");
        printf(" 4: Check if the stack is empty     5: Check if the stack is full\n\n");
        scanf("%d", &choice);

        switch(choice){
            case 0: exit(0);
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: isEmpty(); break;
            case 5: isFull(); break;
            default: printf("Please choose a correct option!");
        }
    }
    return 0;
}

void push(){
    
}

int pop(){
}

int peek(){
}

bool isEmpty(){
}

bool isFull(){
}