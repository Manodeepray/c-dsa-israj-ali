#include <stdio.h>

void findDuplicates(int arr[], int n) {
    int count = 0, maxCount = 0, mostRepeatedElement;
    

    for(int i = 0; i < n; i++) {
        int currentCount = 1;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                currentCount++;
            }
        }
        if(currentCount > 1) {
            count += (currentCount - 1); 
        }
        if(currentCount > maxCount) {
            maxCount = currentCount;
            mostRepeatedElement = arr[i];
        }
    }
    
    printf("Total number of duplicate elements: %d\n", count);
    printf("Most repeating element: %d (repeated %d times)\n", mostRepeatedElement, maxCount);
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    findDuplicates(arr, n);

    return 0;
}

