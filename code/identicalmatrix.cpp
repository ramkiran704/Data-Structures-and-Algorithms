#include<stdio.h>
int main (){
    int f=0,n,a[10][10],m,i,j,b[10][10];
    printf("enter m & n");
    scanf("%d%d",&m,&n);
    
   
    for(int i=0;i<m;i++){
        for (j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(i!=j && a[i][j]!=1){
                f=1;
            }
        }
    }
    if(f==1){
        printf("Not identical matrix");
    }
    else{
        printf("identical matrix");
    }
}