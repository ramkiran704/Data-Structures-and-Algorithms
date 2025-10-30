#include <stdio.h>
struct Poly{
    int coeff,expo;
}p1[10],p2[10],p3[10];
int ReadPoly(struct Poly p[10]){
    int t;
    printf("\nEnter the Number of terms:");
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("Enter The Coefficient:");
        scanf("%d",&p[i].coeff);
        printf("Enter the expo:");
        scanf("%d",&p[i].expo);
    }
    return t;
}
void Display(struct Poly p[10],int t){
    int i;
    for( i=0;i<t-1;i++){
        printf("%dx^%d+",p[i].coeff,p[i].expo);
    }
    printf("%dx^%d",p[i].coeff,p[i].expo);
}
int AddPoly(struct Poly p1[10],struct Poly p2[10],int t1,int t2,struct Poly p3[10]){
    int i=0,j=0,k=0;
    while(i<t1 && j<t2){
        if(p1[i].expo==p2[j].expo){
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            p3[k].expo=p1[i].expo;
            i++;j++;k++;
        }
        else if(p1[i].expo>p2[j].expo){
            p3[k].coeff=p1[i].coeff;
            p3[k].expo=p1[i].expo;
            i++;k++;
        }
        else{
            p3[k].coeff=p2[j].coeff;
            p3[k].expo=p2[j].expo;
            j++;k++;
        }
    }
    while(i<t1){
        p3[k].coeff=p1[i].coeff;
        p3[k].expo=p1[i].expo;
        i++;k++;
    }
    while(j<t2){
        p3[k].coeff=p2[j].coeff;
        p3[k].expo=p2[j].expo;
        j++;k++;
    }
    return k;
}
int main(){
    int t1,t2,t3;
    t1=ReadPoly(p1);
    printf("1st Polynomial:\n");
    Display(p1,t1);
    t2=ReadPoly(p2);
    printf("2nd Polynomial:\n");
    Display(p2,t2);
    t3=AddPoly(p1,p2,t1,t2,p3);
    printf("Sum:\n");
    Display(p3,t3);
}