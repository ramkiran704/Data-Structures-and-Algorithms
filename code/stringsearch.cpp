#include<stdio.h>
int main(){
    char str2[10],str1[10];
    int flag=0,l1=0,l2=0,k=0,a=0,fl=0;
    printf("enter any string:");
    scanf("%s",str1);
    printf("enter the search string:");
    scanf("%s",str2);
    for(int i=0;str1[i]!='\0';i++){
        l1++;
    }
    for(int i=0;str2[i]!='\0';i++){
        l2++;
    }
    for(int i=0;i<l1;i++){
        if(str1[i]==str2[0]){
            for(int j=i;j<l2+i;j++){
                if(str1[i+j]!=str2[k]){
                    flag=1;
                    k++;
                    break;
                }
                else{
                    k++;
                }
            }
            if(flag==1){
                fl=1;
                a=i;
                break;
            }
        }
    }
    if(fl==1){
        printf("string is present at  %d",a+1);
        
    }else{
        printf("string is not present");
    }
}