#include<stdio.h>
#include<cstring>
int main(){
    int f=0,l,i,j;
    char str[20];
    printf("enter the string:");
    gets(str);
    for(i=0;str[i]!='\0';i++);
    l=i-1;
    for(i=0,j=l;i<j;i++,j--){
        if(str[i]!=str[j]){
            f=1;
            break;
        }
    }
    if (f==0){
        printf("palindrome");
    }
    else{
        printf("Not palindrome");
    }
    return 0;
}