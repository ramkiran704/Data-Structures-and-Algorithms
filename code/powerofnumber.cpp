#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main(){
    int x,y,z;
    printf("enter the number:");
    scanf("%d",&x);
    printf("Enter the power:");
    scanf("%d",&y);
    z=pow(x,y);
    printf("%d",z);
    return 0;

}