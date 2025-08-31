#include<stdio.h>
int main(){

    int n,a[10],t;
    printf("enter n:");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("enter the elements:");
        scanf("%d",&a[i]);
    }



    for (int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if (a[j]>a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    printf("sorted array= \n");
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return  0;    
}