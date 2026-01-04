#include <stdio.h>

#define MAX 100   // maximum possible key value

int hashTable[MAX];

// Initialize hash table
void init() {
    for (int i = 0; i < MAX; i++)
        hashTable[i] = -1;
}

// Insert key
void insert(int key) {
    hashTable[key] = key;
}

// Search key
void search(int key) {
    if (hashTable[key] != -1)
        printf("Key %d Found\n", key);
    else
        printf("Key %d Not Found\n", key);
}


void display() {
    for (int i = 0; i < MAX; i++) {
        if (hashTable[i] != -1)
            printf("Index %d : %d\n", i, hashTable[i]);
    }
}

int main() {
    int keys[] = {5, 12, 25, 40};
    int n = 4;

    init();

    for (int i = 0; i < n; i++)
        insert(keys[i]);

    display();
    search(12);
    search(30);

    return 0;
}
