#include<stdio.h>
int main(){

    int n,a[10],s=0;
    float avg;
    printf("enter n:");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("enter the elements:");
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;i++){
        s=s+a[i];
    }
    printf("sum=%d   ",s);
    avg=s/n;
    printf("avg= %f  ",avg);
    return 0;
}