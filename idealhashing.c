#include <stdio.h>
#define MAX 1000
int hashTable[MAX];
int main() {
    int keys[] = {12, 45, 78, 23};
    int n = 4;
    for (int i = 0; i < MAX; i++)
        hashTable[i] = -1;
    for (int i = 0; i < n; i++) {
        hashTable[keys[i]] = keys[i];
    }
    int searchKey = 45;
    if (hashTable[searchKey] != -1)
        printf("Key %d found\n", searchKey);
    else
        printf("Key not found\n");

    return 0;
}
