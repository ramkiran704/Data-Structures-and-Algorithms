#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the number:";
    cin>>n;
    for (int i=1;i<n+1;i++){
        for (int j=0;j<n-i;j++){
            cout<<" "<<"\n";
        }
         for(int k=1;k<i+1;k++){
            cout<<"*";
        }
    }
    return 0;
}