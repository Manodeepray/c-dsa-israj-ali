#include <stdio.h>

void traverse(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertEnd(int arr[], int *n, int x) {
    arr[*n] = x;
    (*n)++;
    printf("Inserted %d at the end.\n", x);
}

void insertBeginning(int arr[], int *n, int x) {
    for (int i = *n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
    (*n)++;
    printf("Inserted %d at the beginning.\n", x);
}

void insertMiddle(int arr[], int *n, int x) {
    int middle = *n / 2;
    for (int i = *n; i > middle; i--) {
        arr[i] = arr[i - 1];
    }
    arr[middle] = x;
    (*n)++;
    printf("Inserted %d in the middle.\n", x);
}

void insertAfter(int arr[], int *n, int element, int x) {
    int index = -1;
    for (int i = 0; i < *n; i++) {
        if (arr[i] == element) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = *n; i > index + 1; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index + 1] = x;
        (*n)++;
        printf("Inserted %d after %d.\n", x, element);
    } else {
        printf("Element %d not found in the array. Insertion failed.\n", element);
    }
}

void insertBefore(int arr[], int *n, int element, int x) {
    int index = -1;
    for (int i = 0; i < *n; i++) {
        if (arr[i] == element) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = *n; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = x;
        (*n)++;
        printf("Inserted %d before %d.\n", x, element);
    } else {
        printf("Element %d not found in the array. Insertion failed.\n", element);
    }
}

void deleteBeginning(int arr[], int *n) {
    if (*n > 0) {
        for (int i = 0; i < *n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*n)--;
        printf("Deleted the first element.\n");
    } else {
        printf("Array is empty. Deletion failed.\n");
    }
}

void deleteEnd(int arr[], int *n) {
    if (*n > 0) {
        (*n)--;
        printf("Deleted the last element.\n");
    } else {
        printf("Array is empty. Deletion failed.\n");
    }
}

void deleteMiddle(int arr[], int *n) {
    if (*n > 0) {
        int middle = *n / 2;
        for (int i = middle; i < *n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*n)--;
        printf("Deleted an element from the middle.\n");
    } else {
        printf("Array is empty. Deletion failed.\n");
    }
}

void deleteAfter(int arr[], int *n, int element) {
    int index = -1;
    for (int i = 0; i < *n; i++) {
        if (arr[i] == element) {
            index = i;
            break;
        }
    }

    if (index != -1 && index < *n - 1) {
        for (int i = index + 1; i < *n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*n)--;
        printf("Deleted the element after %d.\n", element);
    } else if (index == -1) {
        printf("Element %d not found in the array. Deletion failed.\n", element);
    } else {
        printf("No element found after %d to delete. Deletion failed.\n", element);
    }
}

void deleteBefore(int arr[], int *n, int element) {
    int index = -1;
    for (int i = 0; i < *n; i++) {
        if (arr[i] == element) {
            index = i;
            break;
        }
    }

    if (index != -1 && index > 0) {
        for (int i = index - 1; i < *n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*n)--;
        printf("Deleted the element before %d.\n", element);
    } else if (index == -1) {
        printf("Element %d not found in the array. Deletion failed.\n", element);
    } else {
        printf("No element found before %d to delete. Deletion failed.\n", element);
    }
}

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}

int search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Element %d found at index %d.\n", x, i);
            return i;
        }
    }
    printf("Element %d not found in the array.\n", x);
    return -1;
}

int main() {
    int arr[100]; // Assuming a maximum of 100 elements
    int n = 0;     // Current number of elements
    int option;
    int x, element, index;

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Traverse the array\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the middle\n");
        printf("5. Insert after an element\n");
        printf("6. Insert before an element\n");
        printf("7. Delete from the beginning\n");
        printf("8. Delete from the end\n");
        printf("9. Delete from the middle\n");
        printf("10. Delete after an element\n");
        printf("11. Delete before an element\n");
        printf("12. Sort the array\n");
        printf("13. Search for an element\n");
        printf("14. Stop the loop\n");
        printf("Enter the option number: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                traverse(arr, n);
                break;
            case 2:
                printf("Enter the number you want to insert at the end: ");
                scanf("%d", &x);
                insertEnd(arr, &n, x);
                break;
            case 3:
                printf("Enter the number you want to insert at the beginning: ");
                scanf("%d", &x);
                insertBeginning(arr, &n, x);
                break;
            case 4:
                printf("Enter the number you want to insert in the middle: ");
                scanf("%d", &x);
                insertMiddle(arr, &n, x);
                break;
            case 5:
                printf("Enter the element after which you want to insert: ");
                scanf("%d", &element);
                printf("Enter the number you want to insert: ");
                scanf("%d", &x);
                insertAfter(arr, &n, element, x);
                break;
            case 6:
                printf("Enter the element before which you want to insert: ");
                scanf("%d", &element);
                printf("Enter the number you want to insert: ");
                scanf("%d", &x);
                insertBefore(arr, &n, element, x);
                break;
            case 7:
                deleteBeginning(arr, &n);
                break;
            case 8:
                deleteEnd(arr, &n);
                break;
            case 9:
                deleteMiddle(arr, &n);
                break;
            case 10:
                printf("Enter the element after which you want to delete: ");
                scanf("%d", &element);
                deleteAfter(arr, &n, element);
                break;
            case 11:
                printf("Enter the element before which you want to delete: ");
                scanf("%d", &element);
                deleteBefore(arr, &n, element);
                break;
            case 12:
                sort(arr, n);
                break;
            case 13:
                printf("Enter the element you want to search for: ");
                scanf("%d", &x);
                index = search(arr, n, x);
                break;
            case 14:
                printf("Stopping the loop.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
