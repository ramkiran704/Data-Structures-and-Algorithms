#include <stdio.h>
int arr[50],n;
int BinarySearch(int arr[],int n,int key){
    int flag=0;
    int low=0,high=n-1,mid;
    while(low<=high){
        mid =(low+high)/2;
        if(arr[mid]==key){
            flag=1;
            break;
        }
        else if(arr[mid]>key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if (flag==0){
        printf("Search data Not Found");
    }
    else{
        printf("Search data is Present at %d",mid);
    }

}
int main(){
    int value;
    printf("Enter any number :");
    scanf("%d",&n);
    for (int i =0;i<n;i++){
        printf("Enter Elment:");
        scanf("%d",&arr[i]);
    }
    printf("Enter The element for Search:");
    scanf("%d",&value);
    BinarySearch(arr,n,value);
    return 0;
}