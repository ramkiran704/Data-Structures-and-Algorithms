#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build tree from preorder array
struct Node* buildTree(int nodes[], int* idx, int n) {
    (*idx)++;

    if (*idx >= n || nodes[*idx] == -1) {
        return NULL;
    }

    struct Node* root = createNode(nodes[*idx]);
    root->left = buildTree(nodes, idx, n);
    root->right = buildTree(nodes, idx, n);

    return root;
}

int main() {
    int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int n = sizeof(nodes) / sizeof(nodes[0]);
    int idx = -1;

    struct Node* root = buildTree(nodes, &idx, n);

    if (root != NULL) {
        printf("Root data: %d\n", root->data);
    } else {
        printf("Tree is empty\n");
    }

    return 0;
}
