#include<stdio.h>
struct poly{
    int expo,coeff;
}p1[10],p2[10],p3[10];
int readPoly(struct poly p[]){
    int t;
    printf("\nEnter the number of terms of Polynomials:");
    scanf("%d",&t);
    for(int i=0;i<=t-1;i++){
        printf("Enter Exponent:");
        scanf("%d",&p[i].expo);
        printf("Enter coefficient: ");
        scanf("%d",&p[i].coeff);
    }
    return t;
}


int displayPoly(struct poly p[],int term){
    printf("\nPolynomial:\n");
    for (int i=0;i<term;i++){
        printf("%d(x^%d)+",p[i].coeff,p[i].expo);
    }
}
int addPoly(struct poly p1[],struct poly p2[],int t1,int t2,struct poly p3[]){
    int i=0;
    int j=0;
    int k=0;
    for(;i<t1&&j<t2;){
        if(p1[i].expo==p2[j].expo){
            p3[k].expo=p1[i].expo;
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            i=i+1;
            j=j+1;
            k=k+1;
        }
        else if(p1[i].expo>p2[j].expo){
            p3[k].expo=p1[i].expo;
            p3[k].coeff=p1[i].coeff;
            i=i+1;
            k=k+1;
        }
        else{
            p3[k].expo=p2[j].expo;
            p3[k].coeff=p2[j].coeff;
            j=j+1;
            k=k+1;
        }
    }
    while(j<t2){
        p3[k].expo=p2[j].expo;
        p3[k].coeff=p2[j].coeff;
        j=j+1;
        k=k+1;
    }
    while(i<t1){
        p3[k].expo=p1[i].expo;
        p3[k].coeff=p1[i].coeff;
        i=i+1;
        k=k+1;
    }
    return k;
}
int main(){
    int t1,t2,t3;
    t1=readPoly(p1);
    displayPoly(p1,t1);
    t2=readPoly(p2);
    displayPoly(p2,t2);
    t3=addPoly(p1,p2,t1,t2,p3);
    printf("\nSum of POlynomials:");
    displayPoly(p3,t3);
    return 0;
}