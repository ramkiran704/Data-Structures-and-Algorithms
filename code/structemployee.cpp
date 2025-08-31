#include<stdio.h>
struct emp{
    int emp_no;
    char emp_name[59],emp_id[20];
    float emp_salary;
}s[50];
int main(){
    int n;
    printf("Enter the number of employees:");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("Enter the Name,Employee ID,Salary of Employee:");
        scanf("%s%s%f",s[i].emp_name,s[i].emp_id,&s[i].emp_salary);
    }
    for(int i=0;i<n;i++){
        printf("Name = %s\t Employee ID =%s\t Employee Salary =%f\t",s[i].emp_name,s[i].emp_id,s[i].emp_salary);
        printf("\n");
    }
    return 0;
}