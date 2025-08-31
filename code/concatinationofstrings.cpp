#include<stdio.h>
int main(){
    char str_1[20],str_2[20];
    int j,i;
    printf( "enter the 1st string:");
    scanf("%s",str_1);
    printf( "enter the 2st string:");
    scanf("%s",str_2);
    for (i=0;str_1[i]!='\0';i++);
    for (j=0;str_2[j]!='\0';j++){
        str_1[i]=str_2[j];
        i++;
    }
    str_1[i]='\0';
    printf("concatinated string :  %s",str_1);
}