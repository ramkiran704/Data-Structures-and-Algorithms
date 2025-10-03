#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* left;
    struct Node* right;
    int data;
};

void Insert(int key){
    struct Node* t=root;
    struct Node* r=NULL,*p;
    if(root==NULL){
        p=(struct Node*)malloc(sizeof(struct Node));
        p->dat=key;
        p->left=p->right=NULL;
        root=p;
        return;
    }
    while(t!=NULL){
        r=t;
        if(key<t->data) t=t->left;
        else if(key>t->data) t=t->right;
        else return;
    }
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=key;
    p->right=p->left=NULL;
    if(key<r->data) r->left=key;
    else r->right=key;
}
void inorder(struct Node* p){
    if(p!=NULL){
        inorder(p->left);
        printf("%d",p->data);
        inorder(p->right);
    }
}
int height(struct Node*p){
    int x,y;
    if(p==NULL) return 0;
    x=height(p->left);
    y=height(p->right);
    return x>y?x+1:y+1;
}
struct Node *inPre(struct Node* p){
    while(p&& p->right!=NULL){
        p=p->right;
    }
    return p;
}
struct Node *inSucc(struct Node* p){
    while(p&& p->left!=NULL){
        p=p->left;
    }
    return p;
}

struct Node* Rdeletion(struct Node * p,int key){
    struct Node*q ;
    if(p==NULL){
        return NULL;
    }
    if(p->left==NULL && p->right==NULL){
        if(p==root){
            root=NULL;
        }
        free(p);
    }
    if(key<p->data){
        p->left=Rdeletion(p->left,key);
    }
    else if(key>p->data){
        p->right=Rdeletion(p->right,key);
    }
    else{
        if(height(p->left)>height(p->right)){
            q=inPre(p->left);
            p->data=q->data;
            p->left=Rdeletion(p->left,q->data);
        }
        else{
            q=inSucc(p->right);
            p->data=q->data;
            p->right=Rdeletion(p->right,q->data);
        }
    }
    return p;
}