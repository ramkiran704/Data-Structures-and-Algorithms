#include<stdio.h>
int arr[100][100],m,n;
void readMatrix(int x,int y){
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            printf("Enter Element:");
            scanf("%d",&arr[i][j]);
        }
    }
}
void displayMatrix(int x,int y){
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}
int main(){
    printf("Enter m&n: ");
    scanf("%d%d",&m,&n);
    readMatrix(m,n);
    displayMatrix(m,n);
    return 0;
}