#include<stdio.h>
int main(){
    int l,count;
    char str[20];
    gets(str);
    for (count=0;str[count]!='\0';count++){
        l=l+1;
    }
    printf("%d",l);
}