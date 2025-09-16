#include<stdio.h>
int size=10;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int Build(int arr[],int n,int item){
    if(n>=size){
        printf("Overflow");
        return n;
    }
    n=n+1;
    arr[n]=item;
    int i=n;
    int p=i/2;
    while(p>0 && arr[i]>arr[p]){
        swap(&arr[i],&arr[p]);
        i=p;
        p=i/2;
    }
    return n;
}
int main(){
    int n=0;
    int arr[size],item,terms;
    printf("Enter the Number of Terms:");
    scanf("%d",&terms);
    for(int i=0;i<terms;i++){
        printf("enter the value:");
        scanf("%d",&item);
        n=Build(arr,n,item); 
    }
    printf("Max Heap Elements:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}