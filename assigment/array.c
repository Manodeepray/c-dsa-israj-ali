#include <stdio.h>

void traverse(int arr1[], int n) {
    int i;
    printf("the elements : \n");
    for (i = 0; i < n; i++) {
        printf(" %d ", arr1[i]);
    }
}

void insert_beginning(int arr1[], int *n, int x) {
    int i;
    (*n)++;
    int arr2[*n];
    arr2[0] = x;
    for (i = 1; i < *n; i++) {
        arr2[i] = arr1[i - 1];
    }

    printf("the new array  : \n");
    for (i = 0; i < *n; i++) {
        printf(" %d ", arr2[i]);
    }
}

void insert_end(int arr1[], int *n, int x) {
    int i;
    (*n)++;
    int arr2[*n];
    for (i = 0; i < *n - 1; i++) {
        arr2[i] = arr1[i];
    }
    arr2[*n - 1] = x;

    printf("the new array  : \n");
    for (i = 0; i < *n; i++) {
        printf(" %d ", arr2[i]);
    }
}

void insert_middle(int arr1[], int *n, int x) {
    int i, j;
    (*n)++;
    int arr2[*n];

    if (*n % 2 == 0) {
        j = *n / 2;
    } else {
        j = (*n + 1) / 2;
    }

    for (i = 0; i < j; i++) {
        arr2[i] = arr1[i];
    }

    arr2[j] = x;

    for (i = j + 1; i < *n; i++) {
        arr2[i] = arr1[i - 1];
    }

    printf("the new array  : \n");
    for (i = 0; i < *n; i++) {
        printf(" %d ", arr2[i]);
    }
}

void insert_after(int arr1[], int *n, int x, int y) {
    int i, j;
    (*n)++;
    int arr2[*n];
    for (i = 0; i < *n; i++) {
        if (arr1[i] == x) {
            j = i + 1;
        }
    }
    arr2[0] = x;
    for (i = 0; i < j; i++) {
        arr2[i] = arr1[i];
    }
    arr2[j] = y;

    for (i = j + 1; i < *n; i++) {
        arr2[i] = arr1[i - 1];
    }

    printf("the new array  : \n");
    for (i = 0; i < *n; i++) {
        printf(" %d ", arr2[i]);
    }
}

void insert_before(int arr1[], int *n, int x, int y) {
    int i, j;
    (*n)++;
    int arr2[*n];
    for (i = 0; i < *n; i++) {
        if (arr1[i] == x) {
            j = i;
        }
    }
    arr2[0] = x;
    for (i = 0; i < j; i++) {
        arr2[i] = arr1[i];
    }
    arr2[j] = y;

    for (i = j + 1; i < *n; i++) {
        arr2[i] = arr1[i - 1];
    }

    printf("the new array  : \n");
    for (i = 0; i < *n; i++) {
        printf(" %d ", arr2[i]);
    }
}

void delete_beginning(int arr1[], int *n) {
    int i;
    int arr2[*n];
    int m = (*n) - 1;
    for (i = 0; i < *n - 1; i++) {
        arr2[i] = arr1[i + 1];
    }
    (*n)--;

    printf("the new array  : \n");
    for (i = 0; i < m; i++) {
        printf(" %d ", arr2[i]);
    }
}

void delete_middle(int arr1[], int *n) {
    int i, j;
    if (*n % 2 == 0) {
        j = *n / 2;
    } else {
        j = (*n + 1) / 2;
    }

    int m = (*n) - 1;
    int arr2[m];

    for (i = 0; i < j; i++) {
        arr2[i] = arr1[i];
    }
    for (i = j + 1; i < m; i++) {
        arr2[i - 1] = arr1[i];
    }
    (*n)--;

    printf("the new array  : \n");
    for (i = j + 1; i < m; i++) {
        printf(" %d ", arr2[i]);
    }
}

void delete_end(int arr1[], int *n) {
    int i;
    int arr2[*n];
    int m = (*n) - 1;
    for (i = 0; i < m; i++) {
        arr2[i] = arr1[i];
    }
    (*n)--;

    printf("the new array  : \n");
    for (i = 0; i < m; i++) {
        printf(" %d ", arr2[i]);
    }
}

void delete_after(int arr1[], int *n, int x) {
    int i, j;
    int m = (*n) - 1;
    int arr2[*n];
    for (i = 0; i < *n; i++) {
        if (arr1[i] == x) {
            j = i + 1;
        }
    }
    for (i = 0; i < j; i++) {
        arr2[i] = arr1[i];
    }
    for (i = j; i < m; i++) {
        arr2[i] = arr1[i + 1];
    }
    (*n)--;

    printf("the new array  : \n");
    for (i = 0; i < m; i++) {
        printf(" %d ", arr2[i]);
    }
}

void delete_before(int arr1[], int *n, int x) {
    int i, j;
    int arr2[*n];
    int m = (*n) - 1;
    for (i = 0; i < *n; i++) {
        if (arr1[i] == x) {
            j = i - 1;
        }
    }
    for (i = 0; i < j; i++) {
        arr2[i] = arr1[i];
    }
    for (i = j + 1; i < m; i++) {
        arr2[i] = arr1[i + 1];
    }
    (*n)--;

    printf("the new array  : \n");
    for (i = 0; i < m; i++) {
        printf(" %d ", arr2[i]);
    }
}

void sort(int arr1[], int *n) {
    int i, j;
    int temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }

    printf("the new array  : \n");
    for (i = 0; i < n; i++) {
        printf(" %d ", arr1[i]);
    }
}

int search(int arr1[], int *n, int x) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (arr1[i] == x) {
            j = i + 1;
        }
    }

    printf("the location of the element %d is %d   : \n", x, j);

    return j;
}

int main() {
    int i, n;
    int option;
    printf("enter the no of elements : \n");
    scanf("%d", &n);
    int arr1[n];
    int x, y, z;

    printf("enter the elements : \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    while (1) {
        int option;
        printf("Select an option:\n");
        printf("1. traverse the array \n");
        printf("2. insert at the end\n");
        printf("3. insert at the beginning\n");
        printf("4. insert at the middle\n");
        printf("5. insert after the element\n");
        printf("6. insert before the element\n");
        printf("7. delete from the beginning\n");
        printf("8. delete from the end\n");
        printf("9. delete at the middle\n");
        printf("10. delete after the element\n");
        printf("11. delete before the element\n");
        printf("12. sort the elements\n");
        printf("13. search for the element\n");
        printf("14. stop the loop\n");

        printf("Enter the option number: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                traverse(arr1, n);
                break;
            case 2:
                printf(" enter the no you want to enter :\n");
                scanf("%d", &x);
                insert_end(arr1, &n, x);
                break;
            case 3:
                printf(" enter the no you want to enter :\n");
                scanf("%d", &x);
                insert_beginning(arr1, &n, x);
                break;
            case 4:
                printf(" enter the no you want to enter in the middle :\n");
                scanf("%d", &x);
                insert_middle(arr1, &n, x);
                break;
            case 5:
                printf(" enter the element you want to enter after :\n");
                scanf("%d", &x);
                printf(" enter the no you want to enter :\n");
                scanf("%d", &y);
                insert_after(arr1, &n, x, y);
                break;
            case 6:
                printf(" enter the element you want to enter before :\n");
                scanf("%d", &x);
                printf(" enter the no you want to enter :\n");
                scanf("%d", &y);
                insert_before(arr1, &n, x, y);
                break;
            case 7:
                delete_beginning(arr1, &n);
                break;
            case 8:
                delete_end(arr1, &n);
                break;
            case 9:
                delete_middle(arr1, &n);
                break;
            case 10:
                printf(" enter the element you want to delete after :\n");
                scanf("%d", &x);
                delete_after(arr1, &n, x);
                break;
            case 11:
                printf(" enter the element you want to delete before :\n");
                scanf("%d", &x);
                delete_before(arr1, &n, x);
                break;
            case 12:
                sort(arr1, n);
                break;
            case 13:
                printf(" enter the element you want to search for :\n");
                scanf("%d", &x);
                search(arr1, n, x);
                break;
            case 14:
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

    return 0;
}