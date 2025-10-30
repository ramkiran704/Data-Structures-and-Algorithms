#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define Max 50

struct Node {
    char data;
    struct Node *left, *right;
};

struct Node *stack[Max];
int top = -1;

struct Node* createNode(char ch) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ch;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void Push(struct Node *newNode) {
    if (top < Max - 1)
        stack[++top] = newNode;
    else
        printf("Stack Overflow\n");
}

struct Node* Pop() {
    if (top != -1)
        return stack[top--];
    else
        return NULL;
}

struct Node* buildTree(char postfix[]) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isalnum(ch)) {
            struct Node *newNode = createNode(ch);
            Push(newNode);
        } else {   
            struct Node *newNode = createNode(ch);
            newNode->right = Pop();
            newNode->left = Pop();
            Push(newNode);
        }
    }
    return Pop();
}

void inorder(struct Node *ptr) {
    if (ptr != NULL) {
        inorder(ptr->left);
        printf("%c", ptr->data);
        inorder(ptr->right);
    }
}
void preorder(struct Node* ptr){
    if (ptr != NULL) {
        printf("%c", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
void postorder(struct Node* ptr){
    if (ptr != NULL) {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%c", ptr->data);
    }
}
int main() {
    char postfix[40];
    printf("Enter the Postfix Expression: ");
    scanf("%s", postfix);

    struct Node* temp = buildTree(postfix);
    printf("Inorder Traversal of Expression Tree:\n");
    inorder(temp);
    printf("\n");
    preorder(temp);
    printf("\n");
    postorder(temp);
    return 0;
}
