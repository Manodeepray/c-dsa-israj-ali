#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for SYMBOL with alphabet and frequency
typedef struct SYMBOL {
    char alphabet;
    int frequency;
    struct SYMBOL *left, *right;
} SYMBOL;

// Function to create a new node
SYMBOL* createNode(char alphabet, int frequency) {
    SYMBOL* newNode = (SYMBOL*)malloc(sizeof(SYMBOL));
    newNode->alphabet = alphabet;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to swap two nodes
void swap(SYMBOL **a, SYMBOL **b) {
    SYMBOL* temp = *a;
    *a = *b;
    *b = temp;
}

// Min-Heap priority queue for Huffman Tree construction
typedef struct MinHeap {
    int size;
    SYMBOL* array[MAX_SIZE];
} MinHeap;

// Function to create a MinHeap
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    return minHeap;
}

// Function to heapify the min-heap
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx) {
        swap(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to insert a new node into the min-heap
void insertMinHeap(MinHeap* minHeap, SYMBOL* node) {
    minHeap->size++;
    int i = minHeap->size - 1;
    minHeap->array[i] = node;

    while (i && minHeap->array[i]->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        swap(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the minimum node from the min-heap
SYMBOL* extractMin(MinHeap* minHeap) {
    SYMBOL* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to build a Huffman tree
SYMBOL* buildHuffmanTree(char alphabets[], int frequencies[], int size) {
    SYMBOL *left, *right, *top;

    // Create a min-heap and insert all alphabets with their frequencies
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = createNode(alphabets[i], frequencies[i]);
    }
    minHeap->size = size;

    // Build the Huffman tree
    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    // The remaining node is the root of the Huffman tree
    return extractMin(minHeap);
}

// Function for in-order traversal of the tree
void inorderTraversal(SYMBOL* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        if (root->alphabet != '$') {
            printf("%c  ", root->alphabet);
        }
        inorderTraversal(root->right);
    }
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    char alphabets[n];
    int frequencies[n];

    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &alphabets[i]);
    }

    printf("Enter their frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &frequencies[i]);
    }

    SYMBOL* root = buildHuffmanTree(alphabets, frequencies, n);

    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
