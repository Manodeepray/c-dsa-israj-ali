#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

int comparisons = 0;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void generateAscendingData(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

void generateDescendingData(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

void generateRandomData(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX], n, choice;
    clock_t start, end;
    double cpu_time_used;

    while (1) {
        printf("\nMAIN MENU (MERGE SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. ERROR (EXIT)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4)
            break;

        comparisons = 0;

        printf("Enter the number of elements: ");
        scanf("%d", &n);

        switch (choice) {
            case 1:
                generateAscendingData(arr, n);
                break;
            case 2:
                generateDescendingData(arr, n);
                break;
            case 3:
                generateRandomData(arr, n);
                break;
            default:
                printf("Invalid choice.\n");
                continue;
        }

        printf("\nArray before sorting:\n");
        printArray(arr, n);

        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();

        printf("\nArray sorted using Merge Sort:\n");
        printArray(arr, n);

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("Execution time: %.6f seconds\n", cpu_time_used);
        printf("Number of comparisons: %d\n", comparisons);
    }

    return 0;
}
