#include<stdlib.h>
#include<stdio.h>
int main1(int line_number){
    FILE *fw;
    char ch;
    fw=fopen("sample1.txt","r");
    
    if(fw==NULL){
        printf("NOt opened");
        exit(0);
    }
    ch=fgetc(fw);
    while(ch!=EOF){
       putchar(ch);
    }
    fclose(fw);
    fw=fopen("sample1.txt","a");
    fprintf(fw,"append%d",line_number);
    printf("%d",line_number);
    fclose(fw);
}
int main2(){
    FILE *pr;
    char ch;
    pr=fopen("sample1.txt","r");
    if (pr==NULL){
        printf("not opend");
        exit(0);
    }
    ch=fgetc(pr);
    while (ch!=EOF){
        putchar(ch);
    }
    printf("----------------End -- of -- characters-------------- ");
    fclose(pr);
}
int main(){
    main1(1);
    main2();
}