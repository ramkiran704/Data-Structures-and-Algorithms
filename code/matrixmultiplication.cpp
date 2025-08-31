#include<stdio.h>
int main (){
    int n,a[10][10],m,i,s=0,j,b[10][10],c[10][10];
    printf("enter order of A  & B");
    scanf("%d%d",&m,&n);
    
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
    // multiplication
    for(i=0;i<m;i++){
        for (j=0;j<n;j++){
            c[i][j]=0;
            for (int k=0;k<m;k++){
               c[i][j]+=a[i][k]*b[k][j];
            }   
        }
    }
    printf("multiplation= \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d",c[i][j]);
            printf("\t");
        }
    printf("\n");
    }
}