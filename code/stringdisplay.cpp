#include <stdio.h>
struct hotel
{
    char name[20];
    char address[50];
    char grade;
    float charge_avg;
    int no;
}h[50],temp;

void sort(int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (h[j].charge_avg>h[j+1].charge_avg)
            {
                temp=h[j];
                h[j]=h[j+1];
                h[j+1]=temp;
            }
        }
    }
}

void disp(char g,int n)
{
    for (int i=0;i<n;i++)
    {
        if (strcmp(h[i].grade,g)==0)
        {
            printf("%s\t%s\t%c\t%f\t%d\n",h[i].name,h[i].address,h[i].grade,h[i].charge_avg,h[i].no);

        }
    }
}

void max_charge(float max)
{
    for()
}