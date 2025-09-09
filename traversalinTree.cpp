#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

void inorder(struct Node* node){
    if(node==NULL) return;

    inorder(node->left);
    cout<<"\t"<<node->data;
    inorder(node->right);
}
void preorder(struct Node* node){
    if(node==NULL) return;
    
    cout<<"\t"<<node->data;
    inorder(node->left);  
    inorder(node->right);
}
void postorder(struct Node* node){
    if(node==NULL) return;

    inorder(node->left);
    inorder(node->right);
    cout<<"\t"<<node->data;
}
int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(8);
    root->right->right->left=new Node(9);
    root->right->right->right=new Node(10);
    cout<<"IN ORDER:";
    inorder(root);
    cout<<"\n";
    cout<<"PRE ORDER:";
    preorder(root);
    cout<<"\n";
    cout<<"POST ORDER:";
    postorder(root);
    return 0;
}