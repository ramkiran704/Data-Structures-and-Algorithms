#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Recursive display function (inorder traversal)
void Display(Node* node) {
    if (node == NULL) return;

    Display(node->left);
    cout << node->data << " ";
    Display(node->right);
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    cout << "Tree (inorder traversal): ";
    Display(root);
  
    
    cout << endl;

    return 0;
}
