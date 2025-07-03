#include<stdio.h>
#define n 10
int stack[n],top=-1;
int push (int value){
    if(top==n-1){
        printf("Stack is Full");
    }
    else{
        top++;
        stack[top]=value;
    }
}

int display(){
    if(top==-1){
        printf("Stack is empty");
    }
    else{
        printf("Stack elements:");
        for (int i=0;i<=top;i++){
            printf("%d",stack[i]);
        }
        printf("\n");
    }
}

int main(){
    int x;
    printf("enter data:");
    scanf("%d",&x);
    push(x);
    display();
    return 0;
}