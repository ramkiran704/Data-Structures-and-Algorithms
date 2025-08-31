#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int n,fact=1,i=1;
    cout<<"Enter the number:";
    cin>>n;
    while(i<=n){
        fact=fact*i;
        i++;
    }
    printf(" Factorial= %d",fact);
    return 0;
}