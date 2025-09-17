#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
struct Node* create(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}
struct Node* insert(int val){
    struct Node* newNode=create(val);
    if(head==NULL){
        head=newNode;
        return head;
    }
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}
void display(struct Node* head){
    if(head==NULL){
        printf("Empty");
    }
    while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
int Sum(struct Node* head){
    int sum=0;
    if(head==NULL){
        return sum;
    }
    while(head!=NULL){
        sum+=head->data;
        head=head->next;
    }
    printf("Sum of Node=%d",sum);
}
int main(){
    int arr[49],n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter element:");
        scanf("%d",&arr[i]);
        insert(arr[i]);
    }
    display(head);
    Sum(head);
    return 0;
}