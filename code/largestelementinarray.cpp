#include<stdio.h>
int main(){

    int n,a[10],lar=0;
    printf("enter n:");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("enter the elements:");
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;i++){
        if(lar<a[i]){
            lar=a[i];
        }
    }
    printf("%d",lar);
    return 0;
}