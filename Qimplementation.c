#include<stdio.h>
#define Size 30
int rear=-1;
int front=-1;
int a[Size];

void Enqueue(int item){
    if(rear==Size-1)
    printf("Q is Full\n");
    else if(rear==-1 && front==-1){
        rear=0;
        front=0;
        a[rear]=item;
    }
    else{
        rear++;
        a[rear]=item;
    }
}
void Dequeue(){
    if(front==-1)
    printf("Q is Empty\n");
    else if (rear==front){
        printf("Dequeued%d\n",a[front]);
        front=-1;
        rear=-1;
    }
    else{
        printf("Dequeued%d\n",a[front]);
        front++;
    }

}
void Display(){
    if(front==-1 && rear==-1){
        printf("Q is Empty\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d",a[i]);
        }
        printf("\n");
    }
}
int main(){
    Enqueue(0);
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Display();
    Dequeue();
    Display();
}