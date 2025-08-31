#include<stdio.h>
int fact(int x){
    if(x==0){
        return 1;
    }
    else{
        return x*fact(x-1);
    }
}
int main(){
    int n,rem,sum=0;
    printf("enter any number:");
    scanf("%d",&n);
    int num=n;
    if(n==0){
        printf("INvalid INput");
    }
    for (int i=0;n>0;i++){
        rem=n%10;
        sum+=fact(rem);
        n/=10;
    }
    printf("Sum =%d\n",sum);
    if(num==sum){
        printf("NUmber is strong");
    }
    else{
        printf("NUmber is not strong");
    }
}