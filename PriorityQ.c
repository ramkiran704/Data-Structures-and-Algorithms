#include<stdio.h>
#include<string.h>


struct Customer{
    char name[20];
    char catagory[20];
    int prio;
};
int getPrio(char catagory[]){
    if(strcmp(catagory,"Differentlyabled")==0){
        return 1;
    }
    else if(strcmp(catagory,"Seniorcitizen")==0){
        return 2;
    }
    else if(strcmp(catagory,"Defencepersonnal")==0){
        return 3;
    }
    else{
        return 4;
    }
}
int sortCustomers(struct Customer customers[],int n){
    struct Customer temp;
    for(int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if(customers[i].prio>customers[j].prio){
                temp=customers[i];
                customers[i]=customers[j];
                customers[j]=temp;
            }
        }
    }
}

int main(){
    struct Customer customers[100];
    int n;
    printf("Enter number of customer:");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("Enter the name of customer:");
        scanf("%s",customers[i].name);
        printf("Enter catagory(Differentlyabled/Seniorcitizen/Defencepersonnal/Ordinary):");
        scanf("%s",customers[i].catagory);
        customers[i].prio=getPrio(customers[i].catagory);
    }
    sortCustomers(customers,n);
    printf("\nOrder of service based on priority:\n");
    for(int i=0;i<n;i++){
        printf("%d %s %s\n",i+1,customers[i].name,customers[i].catagory);
    }
    return 0;
}