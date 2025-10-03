#include <stdio.h>
# define Size 30
int stack[Size];
int top=-1;
void Push(int item){
    if(top==Size-1){
        printf("Stack is Full\n");
    }
    else{
        top=top+1;
        stack[top]=item;
    }
}
void Pop(){
    if(top==-1){
        printf("Stack is Empty\n");
    }
    else{
        printf("Poped%d\n",stack[top]);
        top--;
    }

}
void Display(){
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        for(int i=top;i>=0;i--)
        printf("%d\n",stack[i]);
    }
}
int main(){
    Push(1);
    Push(2);
    Push(3);
    Push(4);
    Display();
    Pop();
    Display();
}