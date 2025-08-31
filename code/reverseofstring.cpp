#include<stdio.h>
int main(){
    int l,count;
    char str[20];
    gets(str);
    for (count=0;str[count]!='\0';count++){
        l=l+1;
    }
    for(int i=0;i<l/2;i++){
        char t=str[i];
        str[i]=str[l-i-1];
        str[l-i-1]=t;
    }
    printf("reversed string :%s \n",str);
    return 0;
}