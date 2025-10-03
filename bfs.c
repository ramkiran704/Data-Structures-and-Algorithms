#include<stdio.h>
#include<stdlib.h>

#define Size 20
int queue[Size],front=-1,rear=-1,sv,nv,visited[Size],AM[Size][Size];
void Enqueue(int item){
    if(rear==Size-1){
        printf("Q is Full\n");
        return;
    }
    if(front==-1)
        front=rear=0;
    else{
        rear++;
    }
    queue[rear]=item;
}
int Dequeue(){
    if(front==-1){
        printf("Q is Empty\n");
        return -1;
    }
    int item=queue[front];
    if(front==rear)
        front=rear=-1;
    else
        front++;
    return item;
}
void Bfs(int sv){
    visited[sv]=1;
    Enqueue(sv);
    printf("BFS Traversal:\n");
    while(front!=-1){
        int cv=Dequeue();
        printf("V%d",cv);
        for(int i=0;i<nv;i++){
            if(AM[cv][i]==1 && visited[i]==0){
                visited[i]=1;
                Enqueue(i);
            }
        }
    }
    printf("\n");
}
int main(){
    int ch;
    printf("Enter the NUmber of Vertices:");
    scanf("%d",&nv);
    for(int i=0;i<nv;i++){
        visited[i]=0;
        for(int j=0;j<nv;j++){
            AM[i][j]=0;
        }
    }
    for(int i=0;i<nv;i++){
        for(int j=0;j<nv;j++){
            if(i!=j){
                printf("Do you Want to Create an Edge Between V%d and V%d(Enter 1:Yes 0:No):",i,j);
                scanf("%d",&ch);
                if(ch==1)
                    AM[i][j]=1;
            }
        }
    }
    printf("Adjacency Matrix:\n");
    for(int i=0; i<nv;i++){
        for(int j=0;j<nv;j++){
            printf("%d",AM[i][j]);
        }
        printf("\n");
    }
    printf("Enter the Starting vertex(0 to %d):",nv-1);
    scanf("%d",&sv);
    Bfs(sv);
    return 0;
}