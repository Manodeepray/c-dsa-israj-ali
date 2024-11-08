#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
struct ITEM {
=======
typedef struct {
>>>>>>> e4c9bd554e31610903ed0158b07fd8bbe0625d05
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
<<<<<<< HEAD
};

void swap(struct ITEM* a, struct ITEM* b) {
    struct ITEM temp = *a;
=======
} ITEM;

void swap(ITEM *a, ITEM *b) {
    ITEM temp = *a;
>>>>>>> e4c9bd554e31610903ed0158b07fd8bbe0625d05
    *a = *b;
    *b = temp;
}

<<<<<<< HEAD
void heapify(struct ITEM arr[], int n, int i) {
    int largest = i;
=======
void heapify(ITEM arr[], int n, int i) {
    int largest = i; 
>>>>>>> e4c9bd554e31610903ed0158b07fd8bbe0625d05
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;

    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

<<<<<<< HEAD
void heapSort(struct ITEM arr[], int n) {
=======
void heapSort(ITEM arr[], int n) {
>>>>>>> e4c9bd554e31610903ed0158b07fd8bbe0625d05
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

<<<<<<< HEAD
float fractionalKnapsack(struct ITEM items[], int n, float capacity) {
    float totalProfit = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i].item_weight <= capacity) {
            capacity -= items[i].item_weight;
            totalProfit += items[i].item_profit;
            printf("%d\t\t%.6f\t%.6f\t%.6f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, 1.0);
        } else {
            float fraction = capacity / items[i].item_weight;
            totalProfit += items[i].item_profit * fraction;
            printf("%d\t\t%.6f\t%.6f\t%.6f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, fraction);
            break;
        }
    }
    return totalProfit;
=======
float fractionalKnapsack(ITEM items[], int n, float capacity) {
    float total_profit = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i].item_weight <= capacity) {
            total_profit += items[i].item_profit;
            capacity -= items[i].item_weight;
        } else {
            total_profit += items[i].item_profit * (capacity / items[i].item_weight);
            break;
        }
    }
    return total_profit;
>>>>>>> e4c9bd554e31610903ed0158b07fd8bbe0625d05
}

int main() {
    int n;
    float capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

<<<<<<< HEAD
    struct ITEM items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
=======
    ITEM items[n];

    for (int i = 0; i < n; i++) {
        items[i].item_id = i + 1;
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &items[i].item_profit, &items[i].item_weight);
>>>>>>> e4c9bd554e31610903ed0158b07fd8bbe0625d05
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    heapSort(items, n);

<<<<<<< HEAD
    printf("\nItem No\t\tprofit\t\tWeight\t\tAmount to be taken\n");
    float maxProfit = fractionalKnapsack(items, n, capacity);

    printf("Maximum profit: %.6f\n", maxProfit);
=======
    float max_profit = fractionalKnapsack(items, n, capacity);

    printf("The maximum profit closest to the knapsack capacity is: %.2f\n", max_profit);
>>>>>>> e4c9bd554e31610903ed0158b07fd8bbe0625d05

    return 0;
}
