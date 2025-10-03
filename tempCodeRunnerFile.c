#include<stdio.h>
#include<stdlib.h>
#define Size 20
int stack[Size],sv,top=-1,nv,AM[Size][Size],visited[Size];
void Push(int item){
    if(top==Size){
        printf("Stack Overflow\n");
        return -1;
    }
    else{
        top++;
        stack[top]=item;
    }
}
int Pop(){
    if(top==-1){
        printf("Stack is Empty\n");
        return -1;
    }
    else{
        top--;
        int item=stack[top];
    }
    return item;
}
void Dfs(int sv){
    visited[sv]=1;
    Push(sv);
    printf("DFS Traversal:\n");
    while(top!=-1){
        int cv=Pop();
        printf("V%d",cv);
        for(int i=0;i<nv;i++){
            if(AM[cv][i]==1 && visited[i]==0){
                visited[i]=1;
                Push(i);
            }
        }
    }
    printf("\n");
}
int main(){
    int ch;
    printf("Enter the NUmber of Vertices:");
    scanf ("%d",&nv);
    for(int i=0;i<nv;i++){
        visited[i]=0;
        for(int j=0;j<nv;j++){
            AM[i][j]=0;
        }
    }
    for(int i=0;i<nv;i++){
        for(int j=0;j<nv;j++){
            if(i!=j){
                printf("Do you want to Create an edge between V%d and V%d(Enter 1:Yes 0:No):",i,j);
                scanf("%d",&ch);
                if(ch==1)
                  AM[i][j]=1;
            }
        }
    }
    printf("Adjacency Matrix:");
    for(int i=0;i<nv;i++){
        for(int j=0;j<nv;j++){
            printf("%d",AM[i][j]);
        }
        printf("\n");
    }
    printf("Enter the starting Vertex(0 to %d):",nv-1);
    scanf("%d",&sv);
    Dfs(sv);
    return 0;
}