#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fp;
    char name[30];
    int mark;
    fp=fopen("person.txt","r");
    if(fp==NULL){
        printf("File is not Opened");
        exit(0);
    }
    while(feof(fp)==0){
        fscanf(fp,"%s%d",name,&mark);
        printf("%s%d\n",name,mark);
    }
    fclose(fp);
}