#include <stdio.h>
int n,arr[50],i;

int display(){
    printf("Array:\n");
    for (i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}
int search(){
    int search_ele;
    printf("Enter element to search:");
    scanf("%d",&search_ele);
    for(i=0;i<n;i++){
        if(arr[i]==search_ele){
            printf("Element found at %d",i);
        }
    }
}

int insert(){
    int element,position;
    printf("Enter the position and element:");
    scanf("%d%d",&position,&element);
    for (i=n-1;i>=position;i--){
        arr[i+1]=arr[i];
    }
    arr[position]=element;
    n++;
    display();
}
int delete(){
    int index;
    printf("enter the index of the element:");
    scanf("%d",&index);
    for (i=index;i<=n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
    display();
}
int main(){
    int x;
    printf("Enter the number of Elements:");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Enter Element:");
        scanf("%d",&arr[i]);
    }
    printf("Enter 1:search,2:insert,3:delete,4:display");
    scanf("%d",&x);
    switch(x){
        case 1: search();
                break;
        case 2: insert();
                break;
        case 3: delete();
                break;
        case 4: display();
                break;
        default:printf("Invalid Input");
    }
}