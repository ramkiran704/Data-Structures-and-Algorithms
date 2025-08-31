#include<stdio.h>
int main (){
    int n,a[10][10],m,i,j;
    printf("enter m & n");
    scanf("%d%d",&m,&n);
    
   
    for(int i=0;i<m;i++){
        for (j=0;j<n;j++){
            printf("enter elements:");
            scanf("%d",&a[i][j]);
        }
    }


    for(i=0;i<m;i++){
        for (j=0;j<n;j++){
            printf("%d",a[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    return 0;
}