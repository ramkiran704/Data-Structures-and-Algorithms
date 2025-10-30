#include<stdio.h>
#include<stdlib.h>
#define Size 30
int n,Array[Size],low,high,mid,Temp_Array[Size];
void Display_Array(){
    for(int i=0;i<n;i++){
        printf("%d\t",Array[i]);
    }
}
void BubbleSort(){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(Array[j]>Array[j+1]){
                int temp=Array[j];
                Array[j]=Array[j+1];
                Array[j+1]=temp;
            }
        }
    }
    Display_Array();
}
void InsertionSort(){
    int temp;
    for(int i=1;i<n;i++){
        temp=Array[i];
        int j=i-1;
        while(j>0 && Array[j]>temp){
            Array[j+1]=Array[j];
            j--;
        }
        Array[j+1]=temp;
    }
    Display_Array();
}
void Merge(int low,int mid,int high){
    int i=low; int y=mid+1; int x=low;
    while(x<=mid && y<=high){
        if(Array[x]<=Array[y]){
            Temp_Array[i]=Array[x];
            i++;x++;
        }else{
            Temp_Array[i]=Array[y];
            i++;y++;
        }
    }
    while(x<=mid){
        Temp_Array[i]=Array[x];
        i++;x++;
    }
    while(y<=high){
        Temp_Array[i]=Array[y];
        i++;y++;
    }
    for(int i=low;i<=high;i++){
        Array[i]=Temp_Array[i];
    }
}
void MergeSort(){
    if(low<high){
        mid=(low+high)/2;
        MergeSort(low,mid);
        MergeSort(mid+1,high);
        Merge(low,mid,high);
    }
    Display_Array();
}
int Partition(int low,int high){
    int i=low; int j=high; int loc=low;
    while(low<high){
        while(Array[loc]<=Array[high] && loc<high){high--;}
        if(Array[loc]>Array[high]){
            int temp=Array[loc];
            Array[loc]=Array[high];
            Array[high]=temp;
            loc=high;
            low++;
        }
        while (Array[loc]<=Array[low] && low>loc){low++;}
        if(Array[low]>=Array[loc]){
            int temp=Array[low];
            Array[low]=Array[loc];
            Array[loc]=temp;
            loc=low; high--;
        }
    }
}
void QuickSort(){
    if(low<high){
        int p=Partition(low,high);
        QuickSort(low,p-1);
        QuickSort(p+1,high);
    }
    Display_Array();
}
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
void RadixSort(int Array[], int n) {
    int output[100],count[10], exp = 1;
    int max = getMax(Array, n);
    while (max / exp > 0) {
        for (int i = 0; i < 10; i++)
            count[i] = 0;
        for (int i = 0; i < n; i++)
            count[(Array[i] / exp) % 10]++;
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--) {
            int digit = (Array[i] / exp) % 10;
            output[count[digit] - 1] = Array[i];
            count[digit]--;
        }
        for (int i = 0; i < n; i++)
            Array[i] = output[i];
        exp *= 10;
    }
    Display_Array();
}
int main(){
    printf("Enter the Number of Elements of Array:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){   
        printf("Enter Element:");
        scanf("%d",&Array[i]);
    }
    printf("Bubble Sort:\n"); 
    BubbleSort();
    printf("\n");
    printf("Insertion Sort:\n");
    InsertionSort();
    printf("\n");
    printf("Merge Sort:\n");
    MergeSort();
    printf("\n");
    printf("Quick Sort:\n");
    QuickSort();
    printf("\n");
    printf("Radix Sort:\n");
    RadixSort(Array,n);
    return 0;
}