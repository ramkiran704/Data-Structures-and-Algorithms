#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node* next;
};
int main(){
    struct Node* newNode=(struct Node*)malloc (sizeof(struct Node));
    newNode->data=10;
    newNode->next=NULL;
    printf("Data:%d\n",newNode->data);
    free(newNode);
    return 0;
}