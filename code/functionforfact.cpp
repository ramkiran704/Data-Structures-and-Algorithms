#include<stdio.h>
int fact(int n){
    if (n==0){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
int main(){
    int c, n,r;
    printf("Enter n:");
    scanf("%d",&n);
    c=fact(n);
    printf(" %d",c);
}
