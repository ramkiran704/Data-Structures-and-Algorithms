#include<stdio.h>
int main(){
    int v=0,con=0,sp=0;
    char str[20];
    printf("enter any string:");
    gets(str);
    for(int i=0;str[i]!='\0';i++){
        if (str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
            v++;
        }
        else if(str[i]==' '){
            sp++;
        }
        else{
            con++;
        }
    }
    printf("Vowels =  %d \n",v);
    printf("Consonants =  %d \n",con);
    printf("Space =  %d",sp);
}