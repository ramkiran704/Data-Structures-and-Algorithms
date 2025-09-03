#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char data[40];
    struct Node* Llink;
    struct Node* Rlink;
};
struct Node* head=NULL;
struct Node* curr=NULL;
struct Node* ptr;
int Visit(char url[]){
    struct Node* newNode=(struct Node*)malloc (sizeof(struct Node));
    strcpy(newNode->data,url);
    newNode->Llink=newNode->Rlink=NULL;
    if(head==NULL){
        curr=newNode;
        head=newNode;
    }
    else{
        curr->Rlink=newNode;
        newNode->Llink=curr;
        curr=newNode;
    }
    printf("Visited %s\n",curr->data);
}
int Backward(){
    if(curr==NULL || curr->Llink==NULL){
        printf("URl not available\n");
    }
    else{
        curr=curr->Llink;
        printf("BackWard is %s\n",curr->data);
    }
}
int Forward(){
    if(curr==NULL || curr->Rlink==NULL){
        printf("URl not available\n");
    }
    else{
        curr=curr->Rlink;
        printf("Forward is %s\n",curr->data);
    }
}
int History(){
    struct Node* temp;
    if(head==NULL){
        printf("History is empty\n");
    }
    else{
        temp=head;
        while(temp!=NULL){
            printf("%s\n",temp->data);
            temp=temp->Rlink;
        }
    }
}
int main(){
    int choice;
    char url[40];
    do{
        printf("Enter\n1:Visit\n2:BackWard\n3:Forward\n4:History\n5:Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the url:");
                    scanf("%s",url);
                    Visit(url);
                break;
            case 2:Backward();
                break;
            case 3: Forward();
                break;
            case 4: History();
                break;
            case 5:exit(0);
        }
    }
    while(choice!=5);
    return 0;
}