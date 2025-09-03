#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char data[30];
    struct Node* next;
};
struct Node* head=NULL;
struct Node* tail=NULL;
struct Node* temp;
int Create(char str[]){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data,str);
    if(head==NULL){
        head=newNode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
int Find_and_Replace(char key[],char val[]){
    int flag=0;
    if(head==NULL){
        printf("Empty\n");
    }
    else{
        temp=head;
        while(temp!=NULL){
            if(strcmp(temp->data,key)==0){
                flag=1;
                strcpy(temp->data,val);
            }
            temp=temp->next;
        }
        if(flag==0){
            printf("Search Word is Not present");
        }
        else{
            printf("Word is Successfully Replaced");
        }
    }
}
int Display(){
    temp=head;
    while(temp!=NULL){
        printf("%s ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    int ch;
    char word[30];
    char find_word[30];
    char replace_word[30];
    do{
        printf("\nEnter\n1.insert\n2.find and replace\n3.display\n4.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter Word to Insert:");
                    scanf("%s",word);
                    Create(word);
                    break;
            case 2: printf("Enter the Find word:");
                    scanf("%s",find_word);
                    printf("Enter the Word to replace:");
                    scanf("%s",replace_word);
                    Find_and_Replace(find_word,replace_word);
                    break;
            case 3: Display();
                    break;
            case 4: exit(0);
        }
    }while(1);
    return 0;
}