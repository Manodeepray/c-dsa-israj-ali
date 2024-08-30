#include <stdio.h>


void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}


void ROTATE_RIGHT(int *p1, int p2) {

    for (int i = p2 - 1; i > 0; i--) {
        EXCHANGE(&p1[i], &p1[i-1]);
    }
}

int main() {
    int n;


    printf("Enter the size of the array (N): ");
    scanf("%d", &n);

    int arr[n];


    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int m;
    printf("Enter the number of elements to rotate:\n");
    scanf("%d",&m);	
    printf("Before ROTATE:\t");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    ROTATE_RIGHT(arr, m);


    printf("After ROTATE:\t");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

