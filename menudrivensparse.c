

#include <stdio.h>
int A[10][10],B[10][10],tuple[10][3],tuple1[10][3],ttuple[10][3],C[10][3];
int m,n;
int readMatrix(int A[10][10],int m,int n){
for (int i=0;i<m;i++){
for (int j=0;j<n;j++){
printf("Enter Element:");
scanf("%d",&A[i][j]);
}
}
}

int displayMatrix(int A[10][10],int m,int n){
for (int i=0;i<m;i++){
for (int j=0;j<n;j++){
printf("%d\t",A[i][j]);
}
printf("\n");
}
}

int displayTuple(int tuple[10][3],int m){
for (int i=0;i<m;i++){
for (int j=0;j<3;j++){
printf("%d\t",tuple[i][j]);
}
printf("\n");
}
}

int tupleRep(int A[10][10],int m,int n){
int k =1;
tuple[0][0]=m;
tuple[0][1]=n;
for (int i=0;i<m;i++){
for (int j=0;j<n;j++){
if (A[i][j]!=0){
tuple[k][0]=i;
tuple[k][1]=j;
tuple[k][2]=A[i][j];
k++;
}
}
}
tuple[0][2]=k-1;
return k;
}

int tupleRep2(int B[10][10],int m,int n){
int k =1;
ttuple[0][0]=m;

ttuple[0][1]=n;
for (int i=0;i<m;i++){
for (int j=0;j<n;j++){
if (B[i][j]!=0){
ttuple[k][0]=i;
ttuple[k][1]=j;
ttuple[k][2]=B[i][j];
k++;
}
}
}
ttuple[0][2]=k-1;
return k;
}

int tupleTran(int tuple[10][3],int tuple1[10][3]){
tuple1[0][0]=tuple[0][1];
tuple1[0][1]=tuple[0][0];
tuple1[0][2]=tuple[0][2];
int k=1;
m=tuple[0][1],n=tuple[0][2];
for (int i=0;i<m;i++){
for (int j=1;j<=n;j++){
if(tuple[j][1]==i){
tuple1[k][0]=tuple[j][1];
tuple1[k][1]=tuple[j][0];
tuple1[k][2]=tuple[j][2];
k++;
}
}
}
printf("\nTranspose of Tuple Representation:\n");
displayTuple(tuple1,k);
}

int tupleAdd(int tuple[10][3],int ttuple[10][3]){
int k=1;
int r1=tuple[0][0],r2=ttuple[0][0];
int c1=tuple[0][1],c2=ttuple[0][1];
if(r1!=r2 || c1!=c2){
printf("Incompatible Matrix size");
}
else{
C[0][0]=tuple[0][0];
C[0][1]=tuple[0][1];
m=1,n=1;
for (int i=0;i<=r1;i++){
for (int j=0;j<=c1;j++){
if(tuple[m][0]==i && tuple[m][1]==j && ttuple[n][0]==i && ttuple[n]

[1]==j){

C[k][0]=tuple[m][0];
C[k][1]=tuple[m][1];
C[k][2]=tuple[m][2]+ttuple[n][2];
m=m+1;
n=n+1;

k=k+1;
}
else if(tuple[m][0]==i && tuple[m][1]==j){
C[k][0]=tuple[m][0];
C[k][1]=tuple[m][1];
C[k][2]=tuple[m][2];
m=m+1;
k=k+1;
}
else if(ttuple[n][0]==i && ttuple[n][1]==j){
C[k][0]=ttuple[n][0];
C[k][1]=ttuple[n][1];
C[k][2]=ttuple[n][2];
n=n+1;
k=k+1;
}
}
}
C[0][2]=k-1;
}
printf("Sum of Tuples of Two Sparse Matrix:\n");
displayTuple(C,k);
}

int main(){
int x;
printf("Enter 1:Display Tuple,2:Transpose,3:Addition:");
scanf("%d",&x);
switch (x){
case 1: printf("Enter The Sparse Matrix:\n");
printf("Enter m&n:");
scanf("%d%d",&m,&n);
readMatrix(A,m,n);
printf("Sparse Matrix:\n");
displayMatrix(A,m,n);
int y=tupleRep(A,m,n);
printf("\nTuple Representation Of Matrix:\n");
displayTuple(tuple,y);
break;
case 2: printf("Enter The Sparse Matrix:\n");
printf("Enter m&n:");
scanf("%d%d",&m,&n);
readMatrix(A,m,n);
printf("Sparse Matrix:\n");
displayMatrix(A,m,n);
int z=tupleRep(A,m,n);
printf("Tuple Representation:\n");
displayTuple(tuple,z);
tupleTran(tuple,tuple1);
break;
case 3: printf("Enter The Sparse Matrix A:\n");
printf("Enter m&n:");
scanf("%d%d",&m,&n);
readMatrix(A,m,n);
printf("Enter The Sparse Matrix B:\n");

printf("Enter m&n:");
scanf("%d%d",&m,&n);
readMatrix(B,m,n);
printf("Sparse Matrix A:\n");
displayMatrix(A,m,n);
printf("Sparse Matrix B:\n");
displayMatrix(B,m,n);
int p=tupleRep(A,m,n);
int q=tupleRep2(B,m,n);
printf("Tuple of A:\n");
displayTuple(tuple,p);
printf("Tuple of B:\n");
displayTuple(ttuple,q);
tupleAdd(tuple,ttuple);
break;
default: printf("Invalid Input");
}