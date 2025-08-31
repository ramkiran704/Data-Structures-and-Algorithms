#include<stdio.h>
int main(){
    int i=2,n,rem;
    printf("enter any no:");
    scanf("%d",&n);
    int k=n/2;
    while(i<=k){
        rem=n%2;
        if(rem==0){
            printf("%d",rem);
        }
        else{
            continue;
        }

        i++;
    }
    
}