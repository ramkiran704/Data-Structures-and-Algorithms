#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define PRIME 101

struct Node {
    int data;
    struct Node* next;
};

struct Node* hashTable[SIZE];

int a = 3;   // random value (1 < a < p)
int b = 7;   // random value (0 ≤ b < p)

// Universal hash function
int hash(int key) {
    return ((a * key + b) % PRIME) % SIZE;
}

// Insert key
void insert(int key) {
    int index = hash(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search key
void search(int key) {
    int index = hash(key);
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Key %d Found at index %d\n", key, index);
            return;
        }
        temp = temp->next;
    }
    printf("Key %d Not Found\n", key);
}

// Display table
void display() {
    for (int i = 0; i < SIZE; i++) {
        struct Node* temp = hashTable[i];
        printf("Index %d : ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int keys[] = {15, 25, 35, 95, 45};
    int n = 5;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    for (int i = 0; i < n; i++)
        insert(keys[i]);

    display();
    search(35);
    search(50);

    return 0;
}
