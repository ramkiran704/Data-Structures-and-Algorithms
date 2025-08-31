#include<stdio.h>
#include<string.h>
void reverse(char *str){
    char temp;
    int l;
    l=strlen(str);
    for (int i=0;i<l/2;i++){
        temp=str[i];
        str[i]=str[l-i-1];
        str[l-i-1]=temp;
    }
}
int main(){
    
    char str[30];
    printf("enter any string:");
    scanf("%s",str);
    printf("String:   %s",str);
    reverse(str);
    printf("\nReversed String:   %s",str);
}