#include<stdio.h>
#include<math.h>

int main(){
    int sum=0,n,x;
    printf("enter any number:");
    scanf("%d",&n);
    printf("enter any number for x:");
    scanf("%d",&x);
    for(int i=0;i<n;i++){
        sum+=pow(x,i);
    }
    printf("SUm=%d",sum);
}