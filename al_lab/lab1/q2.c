#include <stdio.h>

void computePrefixSum(int arr[], int prefixSum[], int n) {
    prefixSum[0] = arr[0]; 
    
    for(int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i-1] + arr[i]; 
    }
    
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n], prefixSum[n];
    
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    

    computePrefixSum(arr, prefixSum, n);
    

    printf("Prefix Sum Array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");
    
    return 0;
}

