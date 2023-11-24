#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Structure to represent a key-value pair
struct KeyValue
{
    int key;
    int value;
};

// Structure to represent a hash table
struct HashTable
{
    struct KeyValue *array;
    int size;
};

// Function to initialize a hash table
struct HashTable *initHashTable(int size)
{
    struct HashTable *table = (struct HashTable *)malloc(sizeof(struct HashTable));
    table->array = (struct KeyValue *)malloc(size * sizeof(struct KeyValue));
    table->size = size;

    // Initialize all keys to -1 (indicating empty slot)
    for (int i = 0; i < size; i++)
    {
        table->array[i].key = -1;
    }

    return table;
}

// Function to calculate the hash value
int hashCode(int key, int size)
{
    return key % size;
}

// Function to insert a key-value pair into the hash table using linear probing
void insert(struct HashTable *table, int key, int value)
{
    int index = hashCode(key, table->size);

    while (table->array[index].key != -1)
    {
        // Linear probing: move to the next slot if the current slot is occupied
        index = (index + 1) % table->size;
    }

    // Insert the key-value pair into the found slot
    table->array[index].key = key;
    table->array[index].value = value;
}

// Function to search for a key in the hash table
int search(struct HashTable *table, int key)
{
    int index = hashCode(key, table->size);
    int searches = 1;

    while (table->array[index].key != key)
    {
        // Linear probing: move to the next slot if the current slot is not the target key
        index = (index + 1) % table->size;
        searches++;

        // If an empty slot is encountered, the key is not present in the table
        if (table->array[index].key == -1)
        {
            printf("Key %d not found in the hash table.\n", key);
            return searches;
        }
    }

    // Key found in the table
    printf("Key %d found in the hash table at index %d.\n", key, index);
    return searches;
}

// Function to display the content of the hash table
void display(struct HashTable *table)
{
    printf("Hash Table:\n");
    for (int i = 0; i < table->size; i++)
    {
        if (table->array[i].key != -1)
        {
            printf("Index %d: Key %d, Value %d\n", i, table->array[i].key, table->array[i].value);
        }
    }
}

int main()
{
    struct HashTable *table = initHashTable(SIZE);

    insert(table, 1, 10);
    insert(table, 2, 20);
    insert(table, 3, 30);

    display(table);
    printf("Roll NO. 2230028 NAME : MANODEEP RAY");
    int keyToSearch;
    printf("\nEnter key to search: ");
    scanf("%d", &keyToSearch);

    int searches = search(table, keyToSearch);
    printf("Number of searches: %d\n", searches);

    free(table->array);
    free(table);

    return 0;
}
