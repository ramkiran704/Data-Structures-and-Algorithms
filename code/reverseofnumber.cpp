#include <stdio.h>
int main()
{
    int n,d,rev=0;
    printf("enter the numbers:");
    scanf("%d",&n);
    while(n>=0){
        d=n%10;
        rev=rev*10+d;
        n=n/10;
    }
    printf("%d reverse=",rev);
}