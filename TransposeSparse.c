#include <stdio.h>
int A[10][10],S[20][3],T[20][3];
int m1,n1,i,j;
void Display(int X[20][3]){
    printf("Tuple Representation\n");
    for(i=0;i<=X[0][2];i++){
        for(j=0;j<3;j++){
            printf("%d\t",X[i][j]);
        }
        printf("\n");
    }
}
void Sparse(int A[10][10],int m,int n,int S[20][3]){
    int k=1;
    S[0][0]=m;
    S[0][1]=n;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(A[i][j]!=0){
                S[k][0]=i;
                S[k][1]=j;
                S[k][2]=A[i][j];
                k++;
            }
        }
    }
    S[0][2]=k-1;
    Display(S);
}
void TranSparse(int S[20][3],int T[20][3]){
    T[0][0]=S[0][1];
    T[0][1]=S[0][0];
    T[0][2]=S[0][2];
    int k=1,m=S[0][1],n=S[0][2];
    for(i=0;i<m;i++){
        for(j=0;j<=n;j++){
            if(S[j][1]==i){
                T[k][0]=S[j][1];
                T[k][1]=S[j][0];
                T[k][2]=S[j][2];
                k++;
            }
        }
    }
    printf("Transpose:\n");
      for(i=0;i<=T[0][2];i++){
        for(j=0;j<3;j++){
            printf("%d\t",T[i][j]);
        }
        printf("\n");
    }
}
int main(){
    printf("Enter the m&n of  Matrix:");
    scanf("%d%d",&m1,&n1);
    printf("\nEnter the 1st Matrix:\n");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++){
            printf("Enter the Element:");
            scanf("%d",&A[i][j]);
        }
    }
   
    printf("Matrix :\n");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++){
            printf("%d",A[i][j]);
        }
        printf("\n");
    }
    Sparse(A,m1,n1,S);
    TranSparse(S,T);
    return 0;
}