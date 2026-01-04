#include <stdio.h>
#include<stdlib.h>
int main(){
    int r,c,i,j,*arr;
    printf("Enter the  row:");
    scanf("%d",&r);
    printf("Enter the  column:");
    scanf("%d",&c);
    
    arr=(int*)malloc(r*c*sizeof(int));
    if(arr==NULL){
        printf("Error! memory allocation failed");
        exit(0);
    }
    printf("enter %d elements:",r*c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",(arr+i*c+j));
        }
    }
    printf("The matrix:\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d\t",*(arr+i*c+j));
        }
        printf("\n");
    }
    free(arr);
    return 0;
}