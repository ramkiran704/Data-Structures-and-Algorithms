#include<stdio.h>
#include<math.h>
struct point{
    float x,y;
};
float dist(struct point p1,struct point p2){
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

int main(){
    struct point p1,p2;
    float distance;
    printf("enter the 1st point: ");
    scanf("%f%f",&p1.x,&p1.y);
    printf("enter the 2nd point: ");
    scanf("%f%f",&p2.x,&p2.y);
    distance=dist(p1,p2);
    printf("Distance =  %f",distance);
}