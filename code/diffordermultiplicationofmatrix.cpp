#include<stdio.h>
int main (){
    int n,a[10][10],m,i,p,q,s=0,j,b[10][10],c[10][10];
    printf("enter order of A m & n");
    scanf("%d%d",&m,&n);
    printf("enter order of B p & q");
    scanf("%d%d",&p,&q);
    
    printf("enter the matrix A \n");
    for(int i=0;i<m;i++){
        for (j=0;j<n;j++){
            printf("enter elements:");
            scanf("%d",&a[i][j]);
        }
    }

    printf("enter the matrix B \n");
    for(i=0;i<p;i++){
        for (j=0;j<q;j++){
            printf("enter elments:");
            scanf("%d",&b[i][j]);
        }
    }
    // multiplication
    for(i=0;i<m;i++){
        for (j=0;j<n;j++){
            for(int x=0;x<p;x++){
                for(int y=0;y<q;y++){
                    s=a[i][j]*b[y][x];
                    for (int k=0;k<m;k++){
                        for(int l=0;l<n;l++){
                        c[k][l]=s+s+s;
                    }
                }
            }
        }
    }
    printf("multiplation= \n");
        for(i=0;i<p;i++){
            for(j=0;j<q;j++){
                printf("%d",c[i][j]);
                printf("\t");
            }
        printf("\n");
        }
}