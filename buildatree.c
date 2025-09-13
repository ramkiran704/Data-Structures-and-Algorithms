#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(int key){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=key;
    newNode->left=newNode->right=NULL;
    return newNode;
}
struct node* addChild(struct node* par,struct node* child){
    if(par->left==NULL){
        par->left=child;
    }else{
        struct node* temp=par->left;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        temp->right=child;
    }
}

struct node* searchNode(struct node* root,int key) {
    if (root == NULL) return NULL;

    if (root->data== key)
        return root;
    struct node* found = searchNode(root->left, key);
    if (found) return found;
    return searchNode(root->right, key);
}
void display(struct node* root, int level) {
    if (root == NULL) return;

    for (int i = 0; i < level; i++) printf("  ");
    printf("%d\n", root->data);

    display(root->left, level + 1);
    display(root->right, level);
}
int main(){
    int choice,val,parentnode,childdata;
    struct node* root=NULL;
    do{
        printf("Enter\n1:Add Root\n2:Add Child\n3:Display\n4:Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(root!=NULL){
                    printf("root is already exist\n");
                    break;
                }
                else{
                    printf("enter the root data:\n");
                    scanf("%d",&val);
                    root=createNode(val);
                }
                break;
            case 2:
                if(root==NULL){
                    printf("enter the root first\n");
                    break;
                }
                else{
                    printf("enter the parent node:\n");
                    scanf("%d",&parentnode);
                    struct node* par=searchNode(root,parentnode);
                    if(par==NULL){
                        printf("parent not exist\n");
                    }
                    else{
                        printf("enter teh child data\n");
                        scanf("%d",&childdata);
                        struct node* child=createNode(childdata);
                        addChild(par,child);
                    }
                    break;
                }
                case 3:
                    if (root == NULL) {
                        printf("Tree is empty!\n");
                    } else {
                        printf("\nTree structure:\n");
                        display(root, 0);
                    }
                    break;
                    case 4:exit(1);
        }
    }while(choice!=4);
}