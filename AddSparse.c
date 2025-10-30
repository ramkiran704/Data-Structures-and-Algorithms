#include <stdio.h>
int A[10][10],B[10][10],S[20][3],T[20][3];
int m1,n1,i,j,m2,n2;
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
void AddSparse(int S[20][3],int T[20][3]){
    int r1,c1,r2,c2,k,C[20][3],m,n;
    r1=S[0][0];c1=S[0][1];
    r2=T[0][0];c2=T[0][1];
    if(r1!=r2 || c1!=c2)
        printf("Incompatible Matrix Size.\n");
    else{
        C[0][0]=S[0][0]; C[0][1]=S[0][1];
        m=1;n=1;k=1;
        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++){
                if(S[m][0]==i && S[m][1]==j && T[n][0]==i && T[n][1]==j){
                    C[k][0]=S[m][0];
                    C[k][1]=S[m][1];
                    C[k][2]=S[m][2]+T[n][2];
                    m++;n++;k++;
                }
                else if(S[m][0]==i && S[m][1]==j){
                    C[k][0]=S[m][0];
                    C[k][1]=S[m][1];
                    C[k][2]=S[m][2];
                    m++;k++;
                }
                else if(T[n][0]==i && S[n][1]==j){
                     C[k][0]=T[n][0];
                    C[k][1]=T[n][1];
                    C[k][2]=T[n][2];
                    n++;k++;
                }
            }
        }
        while (m <= S[0][2]) {
            C[k][0] = S[m][0];
            C[k][1] = S[m][1];
            C[k][2] = S[m][2];
            m++; k++;
        }

        while (n <= T[0][2]) {
            C[k][0] = T[n][0];
            C[k][1] = T[n][1];
            C[k][2] = T[n][2];
            n++; k++;
        }
        C[0][2]=k-1;
    }
    printf("Sum of Two Matrix:\n");
     for(i=0;i<=C[0][2];i++){
        for(j=0;j<3;j++){
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
}
int main(){
    printf("Enter the m&n of 1st Matrix:");
    scanf("%d%d",&m1,&n1);
    printf("\nEnter the 1st Matrix:\n");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++){
            printf("Enter the Element:");
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter the m&n of 2nd Matrix:\n");
    scanf("%d%d",&m2,&n2);
    printf("\nEnter the 2nd Matrix:\n");
    for(i=0;i<m2;i++){
        for(j=0;j<n2;j++){
            printf("Enter the Element:");
            scanf("%d",&B[i][j]);
        }
    }
    printf("Matrix 1:\n");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++){
            printf("%d",A[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2:\n");
    for(i=0;i<m2;i++){
        for(j=0;j<n2;j++){
            printf("%d",B[i][j]);
        }
        printf("\n");
    }
    Sparse(A,m1,n1,S);
    Sparse(B,m2,n2,T);
    AddSparse(S,T);
    return 0;
}