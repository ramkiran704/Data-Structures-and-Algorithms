#include<stdio.h>
int main(){

    int n,a[n];
    printf("enter n:");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("enter the elements:");
        scanf("%d",&a[i]);
    }
    printf("elements are:");
    for (int i=0 ;i<n;i++){
        printf("%d",a[i]);
        printf("\t");
    }
    return 0;
}