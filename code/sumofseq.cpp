#include<stdio.h>
#include<math.h>

int fact(int y){
    if(y==0){
        return 1;
    }
    else{
        return y*(y-1);
    }
}
int main(){
    int n,sum=0,x,sign=1,term;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    printf("Enter the number:");
    scanf("%d",&x);
    int i=1;
    for(int j=0;j<n;j++){
        term=pow(x,i)/(fact(i));
        sum+=sign*term;
        sign*=-1;
        i+=2;
    }
    printf("sum=%d",sum);
}