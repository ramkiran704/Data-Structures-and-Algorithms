#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fp;
    char c;
    fp=fopen("sample.txt","r");
    if(fp==NULL){
        printf("File is not Opened");
        exit(0);
    }
    while(feof(fp)==0){
        
        c=fgetc(fp);
        putc(c,stdout);
        
    }printf("opened successfully");
    fclose(fp);
}