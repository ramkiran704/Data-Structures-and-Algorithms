#include <stdio.h>
#include<stdlib.h>
struct Node{
    int expo;
    int coeff;
    struct Node* next;
};
struct Node* createNode(int coeff,int expo){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->expo=expo;
    newNode->coeff=coeff;
    newNode->next=NULL;
    return newNode;
}
void display(struct Node* poly){
    while(poly!=NULL){
        printf("%dx^%d",poly->coeff,poly->expo);
        if(poly->next!=NULL){
            printf("+");
        }
        poly=poly->next;
    }
    printf("\n");
}

struct Node* Multiplication(struct Node* poly1, struct Node* poly2) {
    struct Node* resultPoly = NULL;

    struct Node* ptr1 = poly1;
    while (ptr1 != NULL) {
        struct Node* ptr2 = poly2;   
        while (ptr2 != NULL) {
            int coeff = ptr1->coeff * ptr2->coeff;
            int expo = ptr1->expo + ptr2->expo;

            struct Node* temp = resultPoly, *prev = NULL;
            while (temp != NULL && temp->expo > expo) {
                prev = temp;
                temp = temp->next;
            }

            if (temp != NULL && temp->expo == expo) {
                temp->coeff += coeff;
            } else {
                struct Node* newNode = createNode(coeff, expo);
                if (prev == NULL) {
                    newNode->next = resultPoly;
                    resultPoly = newNode;
                } else {
                    newNode->next = prev->next;
                    prev->next = newNode;
                }
            }

            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    return resultPoly;   
}
struct Node* Addition(struct Node* poly1, struct Node* poly2) {
    struct Node* resultPoly = NULL, *prev = NULL;
    struct Node* ptr1 = poly1;
    struct Node* ptr2 = poly2;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->expo == ptr2->expo) {
            int coeff = ptr1->coeff + ptr2->coeff;
            int expo = ptr1->expo;
            if (coeff != 0) {  // skip zero terms
                struct Node* newNode = createNode(coeff, expo);
                if (resultPoly == NULL) {
                    prev = resultPoly = newNode;
                } else {
                    prev->next = newNode;
                    prev = newNode;
                }
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } 
        else if (ptr1->expo > ptr2->expo) {
            struct Node* newNode = createNode(ptr1->coeff, ptr1->expo);
            if (resultPoly == NULL) {
                prev = resultPoly = newNode;
            } else {
                prev->next = newNode;
                prev = newNode;
            }
            ptr1 = ptr1->next;
        } 
        else {
            struct Node* newNode = createNode(ptr2->coeff, ptr2->expo);
            if (resultPoly == NULL) {
                prev = resultPoly = newNode;
            } else {
                prev->next = newNode;
                prev = newNode;
            }
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL) {
        struct Node* newNode = createNode(ptr1->coeff, ptr1->expo);
        if (resultPoly == NULL) {
            resultPoly = prev = newNode;
        } else {
            prev->next = newNode;
            prev = newNode;
        }
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        struct Node* newNode = createNode(ptr2->coeff, ptr2->expo);
        if (resultPoly == NULL) {
            resultPoly = prev = newNode;
        } else {
            prev->next = newNode;
            prev = newNode;
        }
        ptr2 = ptr2->next;
    }

    return resultPoly;
}

int main(){
    struct Node* poly1=NULL;
    struct Node* poly2=NULL;
    struct Node* temp=NULL;
    int n,coeff,expo;

    printf("Enter the Number of Terms of Polynomial 1:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the Coefficient:");
        scanf("%d",&coeff);
        printf("Enter the Exponent:");
        scanf("%d",&expo);
        struct Node* newNode=createNode(coeff,expo);
        if(poly1==NULL){
            poly1=temp=newNode;
        }
        else{
            temp->next=newNode;
            temp=newNode;
        }
    }
    printf("Enter the Number of Terms of Polynomial 2:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the Coefficient:");
        scanf("%d",&coeff);
        printf("Enter the Exponent:");
        scanf("%d",&expo);
        struct Node* newNode=createNode(coeff,expo);
        if(poly2==NULL){
            poly2=temp=newNode;
        }
        else{
            temp->next=newNode;
            temp=newNode;
        }
    }
    printf("Polynomial 1\n");
    display(poly1);
    printf("Polynomial 2\n");
    display(poly2);
    printf("Multiplication\n");
    struct Node* resultMUl=Multiplication(poly1,poly2);
    display(resultMUl);
    printf("Addition\n");
    struct Node* resultAdd=Addition(poly1,poly2);
    display(resultAdd);
    return 0;
}
