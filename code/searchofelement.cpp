#include<stdio.h>
int main(){

    int n,a[10],f=0,start=0;
    printf("enter n:");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("enter the elements:");
        scanf("%d",&a[i]);
    }
    printf("enter the search element:");
    scanf("%d",&start);
    for (int i=0;i<n;i++){
        if (start==a[i]){
            f=1;
        }
    }

    if(f==1){
        printf(" found");
    }
    else{
        printf("not found");
    }
    
}