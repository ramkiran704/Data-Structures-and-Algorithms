#include<stdio.h>
int main(){
    int i=2,flag=0,rem,n;
    printf("enter the number:");
    scanf("%d",&n);
    while(i<=n/2){
        rem=n%2;
        if (rem==0){
            flag+=1;
        }
        i++;
    }
    if (flag==0){
        printf("prime");
    }
    else{
        printf("not prime");
    }
    return 0;

}