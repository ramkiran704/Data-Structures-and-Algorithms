#include<iostream>
int main(){
    int a=5,b=8,c=9,d;
    d=a++ + --b + c++;
    printf("%d",a);
    printf("\n");
    printf("%d",b); printf("\n");
    printf("%d",c); printf("\n");
    printf("%d",d);
}