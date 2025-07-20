#include <stdio.h>

int arr[10];
int size, f, r;

void Display_Q() {
    if(f==-1){
        printf("Queue Is Empty\n");
    }
    else{
        for(int i=f;i<=r;i++){
            printf("%d\t",arr[i]);
        }
    }
}

void Dequeue_Q() {
    if(f==-1){
        printf("Queue is Empty\n");
    }
    else if (r==f){
        printf("%d Is Successfully Deleted",arr[f]);
        f=-1;
        r=-1;
    }
    else{
        printf("%d Is Successfully Deleted ",arr[f]);
        f=f+1;
    }
}

int Enqueue_Q(int item) {
    if (r == size - 1) {
        printf("Queue is Full\n");
    } 
    else if(r==-1){
        f=0;r=0;
        arr[r]=item;
    }
    else{
        r++;
        arr[r]=item;
    }
}

int main() {
    int choose, x, element;
    f=-1;
    r=-1;
    printf("Enter the Size of Queue: \n");
    scanf("%d", &size);
    do{
        printf("\nEnter 1: Enqueue, 2: Dequeue, 3:Display:, 4:Exit:");
        scanf("%d", &choose);
        switch (choose) {
            case 1: printf("Enter the Item to Insert:\n");
                    scanf("%d",&element);
                    Enqueue_Q(element);
                    break;
            case 2: Dequeue_Q();
                    break;
            case 3: Display_Q();
                    break;
            case 4: break;
            default:
                printf("Invalid Choice\n");
        }
    }while(choose!=4);
    return 0;
}