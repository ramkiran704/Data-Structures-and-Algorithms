#include<stdio.h>
int main (){
    int n,a[10][10],m,i,j,b[10][10],c[10][10],p,q;
    printf("enter m & n");
    scanf("%d%d",&m,&n);
    printf("enter order of B p & q");
    scanf("%d%d",&p,&q);
            
    // addition
    if (m==p && n==q){
        printf("enter the matrix A \n");
        for(int i=0;i<m;i++){
            for (j=0;j<n;j++){
                printf("enter elements:");
                scanf("%d",&a[i][j]);
            }
        }

        printf("enter the matrix B \n");
        for(i=0;i<m;i++){
            for (j=0;j<n;j++){
                printf("enter elments:");
                scanf("%d",&b[i][j]);
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                c[i][j]=a[i][j]+b[i][j];
            }
        }
    
        printf("Sum= \n");
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                printf("%d",c[i][j]);
                printf("\t");
            }
        printf("\n");
        }
    }
    else{
        printf("addition is not possible");
    }
}
