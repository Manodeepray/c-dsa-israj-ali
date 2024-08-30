#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

int comparisons = 0;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
        printf("\nMAIN MENU (QUICK SORT)\n");
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
        quickSort(arr, 0, n - 1);
        end = clock();

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("\nArray sorted using Quick Sort:\n");
        printArray(arr, n);

        printf("Execution time: %.6f seconds\n", cpu_time_used);
        printf("Number of comparisons: %d\n", comparisons);
    }

    return 0;
}
