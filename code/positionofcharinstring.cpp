#include<stdio.h>
int main(){
    int i,f=0;
    char ch,str[20];
    printf("enter the string:");
    gets(str);
    printf("enter the character to find its position:");
    scanf("%c",&ch);
    for (i=0;str[i]!='\0';i++){
        if (str[i]==ch){
            printf("Position:   %d",i);
            f=1;
        }
        else{
            continue;
        }
    }
    if (f==0){
        printf("charater is not present");
    }

}