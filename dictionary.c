#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char word[40];
    char meaning[40];
    struct Node* left,*right;
};

struct Node* create(char word[],char meaning[]){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word,word);
    strcpy(newNode->meaning,meaning);
    newNode->left=newNode->right=NULL;
    return newNode;
}
struct Node* insert(struct Node* root,char word[],char meaning[]){
    if(root==NULL){
        return create(word,meaning);
    }
    if(strcmp(word,root->word)<0){
        root->left=insert(root->left,word,meaning);
    }
    else if(strcmp(word,root->word)>0){
        root->right=insert(root->right,word,meaning);
    }
    else{
        printf("Word is Already Exists:");
    }
    return root;
}
struct Node* search(struct Node* root,char word[]){
    if(root==NULL || strcmp(root->word,word)==0){
        return root;
    }
    if(strcmp(word,root->word)<0){
        return search(root->left,word);
    }
    else{
        return search(root->right,word);
    }
}
void InorderDisplay(struct Node* root){
    if(root!=NULL){
        InorderDisplay(root->left);
        printf("%s:%s\n",root->word,root->meaning);
        InorderDisplay(root->right);
    }
}
int main(){
    int choice;
    struct Node* root=NULL;
    char word[40],meaning[40];
    do{
        printf("Enter \n1:Insert\n2:Search\n3:Display\n4:Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("-------------Insert-------------\n");
                printf("Enter the Word:");
                scanf("%s",word);
                printf("Enter the Meaning:");
                scanf("%s",meaning);
                root=insert(root,word,meaning);
                break;
        case 2:
                printf("-------------Search--------------\n");
                printf("Enter the Word to Search:");
                scanf("%s",word);
                struct Node* r=search(root,word);
                if(r!=NULL){
                    printf("Meaning of %s:%s",r->word,r->meaning);
                }
                else{
                    printf("Word Not Found");
                }
                break;
        case 3:
                printf("------------Display-------------\n");
                InorderDisplay(root);
                break;
        case 4: 
                exit(1);
                break;
        default:
                printf("Invalid Input");
        }
    }while(1);
    return 0;
}