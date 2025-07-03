#include<stdio.h>
#define n 50
int stack[n],top=-1;
void push(char str){
    if(top==n-1){
        printf("Stack is Full");
    }
    else{
        top++;
        stack[top]=str;
    }
}


void display(){
    if(top==-1){
        printf("Stack is empty");
    }
    else{
        printf("Original String:");
        for (int i=0;i<=top;i++){
            printf("%c",stack[i]);
        }
        printf("\n");
    }
}

void reverse(){
    if(top==-1){
        printf("Stack is empty");
    }
    else{
        printf("Reversed String:");
        for (int i=top;i>=0;i--){
            printf("%c",stack[i]);
        }
        printf("\n");
    }
}
int main(){
    char s[30];
    printf("Enter string:");
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        push(s[i]);
    }
    display();
    reverse();
    return 0;
}