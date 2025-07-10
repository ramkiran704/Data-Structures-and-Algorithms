#include<stdio.h>
int arr[100][100],m,n,tuple[100][3],tTuple[100][3];
int  readMatrix(){
    printf( "Enter m&n:");
    scanf("%d%d",&m,&n);
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            printf("Enter Element:");
            scanf("%d",&arr[i][j]);
        }
    }
}

void displayMatrix(int m,int n){
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}
void displayTupleMatrix(int a[100][3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
int tupleRep(){
    tuple[0][0]=m;
    tuple[0][1]=n;
    int k=1;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if(arr[i][j]!=0){
                tuple[k][0]=i;
                tuple[k][1]=j;
                tuple[k][2]=arr[i][j];
                k=k+1;
                
            }
        }
    }
    tuple[0][2]=k-1;
    return k;
}

int tupleTran(){
    tTuple[0][0]=tuple[0][1];
    tTuple[0][1]=tuple[0][0];
    tTuple[0][2]=tuple[0][2];
    int l=1,m=tuple[0][1],n=tuple[0][2];
    for (int i=0;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(tuple[j][1]==i){
                tTuple[l][0]=tuple[j][1];
                tTuple[l][1]=tuple[j][0];
                tTuple[l][2]=tuple[j][2];
                l++;
            }
        }
    }return l;
} 
int main(){
    int y,x;
    readMatrix();
    printf("\nSparse Matrix:\n");
    displayMatrix(m,n);
    x=tupleRep();
    y=tupleTran();
    printf("\nTuple Representation:\n");
    displayTupleMatrix(tuple,x);
    printf("\nTranspose Of Tuple:\n");
    displayTupleMatrix(tTuple,y);
    return 0;
}