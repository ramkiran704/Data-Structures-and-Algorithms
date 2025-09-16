#include <stdio.h>

#define SIZE 10   // maximum heap size

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Build(int arr[], int n, int item) {
    if (n >= SIZE) {
        printf("Overflow\n");
        return n;
    }

    n = n + 1;
    arr[n] = item;

    int i = n;
    int p = i / 2;

    while (p > 0 && arr[i] > arr[p]) {
        swap(&arr[i], &arr[p]);
        i = p;
        p = i / 2;
    }

    return n;
}
int delete(int arr[],int n,int item){
    int left,right,large,i=0;
    if(n<=0){
        printf("Underflow");
        return n;
    }
    item=arr[i];
    arr[i]=arr[n];
    n--;
    while(2*i<=n){
        left=2*i;
        right=2*i+1;
        large=i;
        if(left<n && arr[left]>arr[i]){
            large=left;
        }
        if(right<n && arr[right]>arr[i]){
            large=right;
        }
        if(large==i){
            break;
        }
        swap(&arr[i],&arr[large]);
        i=large;
    }
}
int main() {
    int n = 0;               
    int arr[SIZE + 1];       
    int item, terms;

    printf("Enter the Number of Terms: ");
    scanf("%d", &terms);

    for (int i = 0; i < terms; i++) {
        printf("Enter the value: ");
        scanf("%d", &item);
        n = Build(arr, n, item);
    }

    printf("Max Heap Elements (level order):\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("enter item to delete");
    scanf("%d",&item);
    delete(arr,n,item);
    printf("After Deletion Max Heap Elements (level order):\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}