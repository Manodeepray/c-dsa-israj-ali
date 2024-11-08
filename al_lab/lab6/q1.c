/*binary  search*/

#include <stdio.h>

void binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    int comparisons = 0;
    int found = 0; // To indicate if the target was found

    while (low <= high) {
        int mid = low + (high - low) / 2;
        comparisons++;

        if (arr[mid] == target) {
            printf("Element %d found at index %d\n", target, mid);
            found = 1;
            break;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", target);
    }
    printf("Number of comparisons made: %d\n", comparisons);
}

int main() {
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements in sorted order:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    binarySearch(arr, size, target);

    return 0;
}



