#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct Node {
    int data;
    struct Node * next;
};
struct Node * hashtable[SIZE];
int hash(int key){
    return key%SIZE;
}
void insert (int key){
    int index =hash(key);
    struct Node * newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=key;
    newNode->next=hashtable[index];
    hashtable[index]=newNode;
}
void Display(){
    for(int i=0;i<SIZE;i++){
        struct Node * temp=hashtable[i];
        printf("Index %d :",i);
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
int main() {
    int keys[] = {15, 25, 36, 97, 40};
    int n = 5;
    for (int i = 0; i < SIZE; i++)
        hashtable[i] = NULL;
    for (int i = 0; i < n; i++)
        insert(keys[i]);
    Display();
    return 0;
}