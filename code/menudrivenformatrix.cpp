#include<stdio.h>
int display(int x[][100],int y[][100],int p,int q){
    printf("A=\n");
    for (int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            printf("%d",x[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    printf("B=\n");
    for (int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            printf("%d",y[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    return 0;
}



int multiply(int x[][100],int y[][100],int p,int q){
    int z[20][20];
    for (int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            z[i][j]=0;
            for(int k=0;k<q;k++){
                z[i][j]=z[i][j]+x[i][k]*y[k][j];
            }
        }
    }
    // To display the result
    for (int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            printf("%d",z[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    return 0;
}


int transpose(int x[][100],int p,int q){
    for (int i=0;i<p;i++){
        for(int j=0;j<q;j++){
        x[i][j]=x[j][i];
        }
    }
    // to display result
    for (int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            printf("%d",x[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    return 0;
}


int addition(int x[][100],int y[][100],int p,int q){
    int z[20][20];
    for (int i=0;i<p;i++){
        for(int j=0;j<q;j++){
        z[i][j]=x[i][j]+y[i][j];
        }
    }
    // To display the result
    for (int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            printf("%d",z[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    return 0;
}

// main function
int main(){
    int a[100][100],b[100][100],c[100][100],n,m,ch;
    printf("enter m,n:");
    scanf("%d%d",&m,&n);
    printf("enter the elements of A:");
    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("enrter the elements of B:");
    for (int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&b[i][j]);
        }
    }
    printf("enter 1=display,2=multiply,3=transpose,4=addition");
    scanf("%d",&ch);
    switch(ch){
        case 1:display(a,b,m,n);
                break;
        case 2:multiply(a,b,m,n);
                break;
        case 3:transpose(a,m,n);
                break;
        case 4:addition(a,b,m,n);
                break;
        default:printf("Invalid Input");
    }
}