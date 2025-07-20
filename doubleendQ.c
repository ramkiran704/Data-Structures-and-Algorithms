#include <stdio.h>

int arr[10];
int size, f, r;

void Display_DQ() {
    if(f==-1){
        printf("Queue Is Empty\n");
    }
    else{
        for(int i=0;i<=r;i++){
            printf("%d\t",arr[i]);
        }
    }
}

void Dequeue_DQ() {
    if(f==-1){
        printf("D Queue is Empty\n");
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

void Eject_DQ(){
    if (f==1){
        printf("D queue is Full\n");
    }
    else if(f==r){
        printf("%d is Successfully Deleted",arr[f]);
        f=-1;
        r=-1;
    }
    else{
        printf("%d is Successfully Deleted",arr[r]);
        r--;
    }
}

int Enqueue_DQ(int item) {
    if (r==size-1 && f==0) {
        printf("Queue is Full\n");
    } 
    else if(r==-1){
        f=0;r=0;
        arr[r]=item;
    }
    else if(f>0){
        f--;
        arr[r]=item;
    }
    else{
        for(int i=r;i>=f;i--){
            arr[i+1]=arr[i];
        }
        arr[f]=item;
        r++;
    }
}
void Inject_DQ(int item) {
    if (r==size-1 && f==0) {
        printf("Queue is Full\n");
    } 
    else if(r==-1){
        f=0;r=0;
        arr[r]=item;
    }
    else if(r<size-1){
        r++;
        arr[r]=item;
    }
    else{
        for(int i=f;i>=r;i++){
            arr[i-1]=arr[i];
        }
        arr[r]=item;
        f--;
    }
}

int main() {
    int choose, x, element;
    f=-1;
    r=-1;
    printf("Enter the Size of Double End Queue: \n");
    scanf("%d", &size);
    do{
        printf("\nEnter 1: Enqueue, 2: Dequeue, 3: Inject:, 4: Eject, 5: Display, 6: Exit:");
        scanf("%d", &choose);
        switch (choose) {
            case 1: printf("Enter the Item to Insert:\n");
                    scanf("%d",&element);
                    Enqueue_DQ(element);
                    break;
            case 2: Dequeue_DQ();
                    break;
            case 3: printf("Enter the Item to Insert:\n");
                    scanf("%d",&element);
                    Inject_DQ(element);
                    break;
            case 4: Eject_DQ();
                    break;
            case 5: Display_DQ();
                    break;
            case 6: break;                    
            default:
                printf("Invalid Choice\n");
        }
    }while(choose!=6);
    return 0;
}