#include<stdio.h>
int main(){
    int col_sum,row_sum,m,n,a[10][10],i,j;
    printf("enter the m n:");
    scanf("%d%d",&m,&n);
    printf("Enter the elements:");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("enter elements:");
            scanf("%d",&a[i][j]);
        }
    }


    // Row sum
     for(i=0;i<m;i++){
        row_sum=0;
        for(j=0;j<n;j++){
            row_sum+=a[i][j];
            a[i+1][j+1]=row_sum;
        }
        a[m][n]=row_sum;
    }
    // Col sum
     for(i=0;i<n;i++){
        col_sum=0;
        for(j=0;j<m;j++){
            col_sum+=a[j][i];
        }
        a[m][n]=col_sum;
    }
    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d",a[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}