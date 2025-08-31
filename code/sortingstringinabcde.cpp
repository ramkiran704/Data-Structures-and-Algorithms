#include<stdio.h>
int main(){
    int i,l,j,count;
    char str[20];
    printf("enter the string:");
    gets(str);
    for (count=0;str[count]!='\0';count++){
        l=l+1;
    }
    for (i=0;i<l;i++){
        for(j=0;j<l-i-1;j++){
            if(str[j]>str[j+1]){
                char temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
    }
    printf("sorted string ");
    for(i=0;i<l;i++){
        printf("%c",str[i]);
    }
    return 0;
}